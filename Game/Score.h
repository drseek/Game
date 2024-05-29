/*
 * Copyright (c) 2024 by Stefan Titze
 * 
 * This software is licensed under the MIT License. 
 * The full terms of the license can be found in the 'license' file included with this distribution.
 */

#ifndef __SCORE_H__
#define __SCORE_H__

#include <memory>

/* interface */ class IStrategy;

/*
 * Score stores the score part of a game round
 */
class Score
{
private:
    std::weak_ptr<const IStrategy> m_FirstStrategy;
    std::weak_ptr<const IStrategy> m_SecondStrategy;
    unsigned m_FirstScore;
    unsigned m_SecondScore;

public:
    Score (std::shared_ptr<const IStrategy> firstStrategy, unsigned firstScore, std::shared_ptr<const IStrategy> secondStrategy, unsigned secondScore);
    Score (const Score&) = delete;
    Score (Score&&) = default;
    ~Score () = default;

    Score& operator= (const Score&) = delete;
    Score& operator= (Score&&) = default;

    std::shared_ptr<const IStrategy> GetFirstStrategy () const;
    std::shared_ptr<const IStrategy> GetSecondStrategy () const;
    const unsigned& GetFirstScore () const;
    const unsigned& GetSecondScore () const;
};

#endif
