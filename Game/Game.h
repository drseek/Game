/*
 * Copyright (c) 2024 by Stefan Titze
 * 
 * This software is licensed under the MIT License. 
 * The full terms of the license can be found in the 'license' file included with this distribution.
 */

#ifndef __GAME_H__
#define __GAME_H__

#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <optional>
#include <utility>
#include <vector>

#include "GameResult.h"
#include "Result.h"
#include "Strategy.h"

/*
 * The Game class implements the game logic.
 * In each round both passed in strategies choose to cooperate or to defect.
 * For each round a Result object is generated and stored in m_Results.
 * When both strategies choose to cooperate, both will get 3 points,
 * when both strategies choose to defect, both will get 1 point,
 * otherwise the strategie that chooses to cooperate will get 5 points and the one that chooses to defect will get 0 points
 * Each strategy is then notified about the result of the current game round
 * At the end of the game the strategy that has the most points wins
 */
template<Strategy First, Strategy Second, unsigned Rounds>
class Game
{
private:
    std::shared_ptr<IStrategy> m_FirstStrategy;
    std::shared_ptr<IStrategy> m_SecondStrategy;
    std::vector<Result> m_Results;
    std::optional<GameResult> m_GameResult;

    int m_NextNonRemovableNotifyHandle {-1}; // negative handlers cannot be unregistered
    int m_NextNotifyHandle {1};
    std::map<int, std::function<void (const Result&)>> m_NotifyRound; // stores callback handlers for the NotifyRound event
    std::map<int, std::function<void (const GameResult&)>> m_NotifyGame; // stores callback handlers for the NotifyGame event

    void NotifyStrategies (const Result& result) const
    {
        for (const auto& notifyFunction: m_NotifyRound)
            notifyFunction.second (result);
    }

    void NotifyGame (const GameResult& result) const
    {
        for (const auto& notifyFunction: m_NotifyGame)
            notifyFunction.second (result);
    }

public:
    explicit Game ()
        : m_FirstStrategy {std::make_shared<First> ()},
        m_SecondStrategy {std::make_shared<Second> ()},
        m_Results {},
        m_GameResult {},
        m_NotifyRound {},
        m_NotifyGame {}
    {
        static_assert (0U != Rounds && "Rounds cannot be 0");

        m_Results.reserve (Rounds);

        std::function<void (const Result&)> notifyFirst {[ptr = m_FirstStrategy.get ()] (const Result& result)
            {
                ptr->NotifyResult (result);
            }};

        std::function<void (const Result&)> notifySecond {[ptr = m_SecondStrategy.get ()] (const Result& result)
            {
                ptr->NotifyResult (result);
            }};

        m_NotifyRound[m_NextNonRemovableNotifyHandle--] = notifyFirst;
        m_NotifyRound[m_NextNonRemovableNotifyHandle--] = notifySecond;
    }

    Game (const Game&) = delete;
    Game (Game&&) = delete;

    ~Game () = default;

    const std::optional<GameResult>& GetGameResult () const
    {
        return m_GameResult;
    }

    void Play ()
    {
        for (unsigned i {}; i < Rounds; ++i)
        {
            auto result {make_result (i, m_FirstStrategy, m_FirstStrategy->ChoosePlay (), m_SecondStrategy, m_SecondStrategy->ChoosePlay ())};
            NotifyStrategies (result);
            m_Results.emplace_back (std::move (result));
        }

        m_GameResult = make_game_result (std::cbegin (m_Results), std::cend (m_Results));
        NotifyGame (m_GameResult.value ());
    }

    int RegisterNotifyRound (const std::function<void (const Result&)>& notifyRound)
    {
        int notifyHandle {m_NextNotifyHandle++};
        m_NotifyRound[notifyHandle] = notifyRound;
        return notifyHandle;
    }

    void UnregisterNotfiyRound (int handle)
    {
        if (0 < handle)
            m_NotifyRound.erase (handle);
    }

    int RegisterNotifyGame (const std::function<void (const GameResult&)>& notifyGame)
    {
        int notifyHandle {m_NextNotifyHandle++};
        m_NotifyGame[notifyHandle] = notifyGame;
        return notifyHandle;
    }

    void UnregisterNotifyGame (int handle)
    {
        if (0 < handle)
            m_NotifyGame.erase (handle);
    }
};

#endif
