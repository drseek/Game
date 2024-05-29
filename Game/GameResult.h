/*
 * Copyright (c) 2024 by Stefan Titze
 * 
 * This software is licensed under the MIT License. 
 * The full terms of the license can be found in the 'license' file included with this distribution.
 */

#ifndef __GAMERESULT_H__
#define __GAMERESULT_H__

#include <concepts>
#include <iterator>
#include <memory>

#include "Result.h"
#include "Score.h"
#include "Strategy.h"

/*
 * GameResult stores the result of a game. It has-a Score -> therefore it inherits privatly from Score
 */
class GameResult : private Score
{
private:
    std::weak_ptr<const IStrategy> m_Winner;

public:
    GameResult (std::shared_ptr<const IStrategy> firstStrategy, unsigned firstScore, std::shared_ptr<const IStrategy> secondStrategy, unsigned secondScore, std::shared_ptr<const IStrategy> winner);
    explicit GameResult (const GameResult&) = delete;
    explicit GameResult (GameResult&&) = default;
    ~GameResult () = default;

    GameResult& operator= (const GameResult&) = delete;
    GameResult& operator= (GameResult&&) = default;

    std::shared_ptr<const IStrategy> GetWinner () const;

    using Score::GetFirstStrategy;
    using Score::GetFirstScore;
    using Score::GetSecondStrategy;
    using Score::GetSecondScore;
};

/*
 * Calculate game result and construct a GameResult
 * InputIterator needs to implement the input_iterator concept and its value_type needs to be of type Result
 */
template<std::input_iterator InputIterator>
requires std::same_as<typename InputIterator::value_type, Result>
GameResult make_game_result (InputIterator beginResult, InputIterator endResult)
{
    std::shared_ptr<const IStrategy> firstStrategy;
    std::shared_ptr<const IStrategy> secondStrategy;
    bool init {true};
    unsigned firstScore {};
    unsigned secondScore {};

    while (beginResult != endResult)
    {
        if (init) // initialize on first loop pass
        {
            firstStrategy = beginResult->GetFirstStrategy ();
            secondStrategy = beginResult->GetSecondStrategy ();
            init = false;
        }

        firstScore += beginResult->GetFirstScore ();
        secondScore += beginResult->GetSecondScore ();

        ++beginResult;
    }

    if (firstScore > secondScore)
        return GameResult {firstStrategy, firstScore, secondStrategy, secondScore, firstStrategy};
    else if (secondScore > firstScore)
        return GameResult {firstStrategy, firstScore, secondStrategy, secondScore, secondStrategy};
    else
        return GameResult {firstStrategy, firstScore, secondStrategy, secondScore, nullptr};
}

#endif
