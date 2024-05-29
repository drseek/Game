/*
 * Copyright (c) 2024 by Stefan Titze
 * 
 * This software is licensed under the MIT License. 
 * The full terms of the license can be found in the 'license' file included with this distribution.
 */

#include "Score.h"

#include "Strategy.h"

using namespace std;

Score::Score (shared_ptr<const IStrategy> firstStrategy, unsigned firstScore, shared_ptr<const IStrategy> secondStrategy, unsigned secondScore)
    : m_FirstStrategy {firstStrategy},
    m_SecondStrategy {secondStrategy},
    m_FirstScore {firstScore},
    m_SecondScore {secondScore}
{}

shared_ptr<const IStrategy> Score::GetFirstStrategy () const
{
    return m_FirstStrategy.lock ();
}

shared_ptr<const IStrategy> Score::GetSecondStrategy () const
{
    return m_SecondStrategy.lock ();
}

const unsigned& Score::GetFirstScore () const
{
    return m_FirstScore;
}

const unsigned& Score::GetSecondScore () const
{
    return m_SecondScore;
}
