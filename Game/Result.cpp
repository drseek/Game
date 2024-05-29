/*
 * Copyright (c) 2024 by Stefan Titze
 * 
 * This software is licensed under the MIT License. 
 * The full terms of the license can be found in the 'license' file included with this distribution.
 */

#include "Result.h"

#include "Strategy.h"

using namespace std;

Result::Result (unsigned round, shared_ptr<const IStrategy> firstStrategy, Play firstPlay, unsigned firstScore, shared_ptr<const IStrategy> secondStrategy, Play secondPlay, unsigned secondScore)
    : Score {firstStrategy, firstScore, secondStrategy, secondScore},
    m_Round {round},
    m_FirstPlay {firstPlay},
    m_SecondPlay {secondPlay}
{}

const unsigned& Result::GetRound () const
{
    return m_Round;
}

const Play& Result::GetFirstPlay () const
{
    return m_FirstPlay;
}
    
const Play& Result::GetSecondPlay () const
{
    return m_SecondPlay;
}

Result make_result (unsigned round, shared_ptr<const IStrategy> firstStrategy, Play firstPlay, shared_ptr<const IStrategy> secondStrategy, Play secondPlay)
{
    unsigned firstScore {};
    unsigned secondScore {};

    if (firstPlay == secondPlay)
    {
        if (Play::Cooperate == firstPlay)
            firstScore = secondScore = 3U;
        else
            firstScore = secondScore = 1U;
    }
    else
    {
        if (Play::Cooperate == firstPlay)
            secondScore = 5U;
        else
            firstScore = 5U;
    }

    return Result {round, firstStrategy, firstPlay, firstScore, secondStrategy, secondPlay, secondScore};
}