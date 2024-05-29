/*
 * Copyright (c) 2024 by Stefan Titze
 * 
 * This software is licensed under the MIT License. 
 * The full terms of the license can be found in the 'license' file included with this distribution.
 */

#include "GameResult.h"

#include "Strategy.h"

using namespace std;

GameResult::GameResult (std::shared_ptr<const IStrategy> firstStrategy, unsigned firstScore, std::shared_ptr<const IStrategy> secondStrategy, unsigned secondScore, std::shared_ptr<const IStrategy> winner)
    : Score {firstStrategy, firstScore, secondStrategy, secondScore},
    m_Winner {winner}
{}

shared_ptr<const IStrategy> GameResult::GetWinner () const
{
    return m_Winner.lock ();
}
