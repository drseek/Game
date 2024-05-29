/*
 * Copyright (c) 2024 by Stefan Titze
 * 
 * This software is licensed under the MIT License. 
 * The full terms of the license can be found in the 'license' file included with this distribution.
 */

#ifndef __RESULT_H__
#define __RESULT_H__

#include <memory>

#include "Play.h"
#include "Score.h"

/* interface */ class IStrategy;

/*
 * Result stores the result of one game round. It has-a Score -> therefore it inherits privatly from Score
 */
class Result : private Score
{
private:
    unsigned m_Round;
    Play m_FirstPlay;
    Play m_SecondPlay;

public:
    Result (unsigned round, std::shared_ptr<const IStrategy> firstStrategy, Play firstPlay, unsigned firstScore, std::shared_ptr<const IStrategy> secondStrategy, Play secondPlay, unsigned secondScore);
    explicit Result (const Result&) = delete;
    explicit Result (Result&&) = default;
    ~Result () = default;

    Result& operator= (const Result&) = delete;
    Result& operator= (Result&&) = default;

    const unsigned& GetRound () const;
    const Play& GetFirstPlay () const;
    const Play& GetSecondPlay () const;

    using Score::GetFirstStrategy;
    using Score::GetSecondStrategy;
    using Score::GetFirstScore;
    using Score::GetSecondScore;
};

Result make_result (unsigned round, std::shared_ptr<const IStrategy> firstStrategy, Play firstPlay, std::shared_ptr<const IStrategy> secondStrategy, Play secondPlay);

#endif
