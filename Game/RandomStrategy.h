/*
 * Copyright (c) 2024 by Stefan Titze
 * 
 * This software is licensed under the MIT License. 
 * The full terms of the license can be found in the 'license' file included with this distribution.
 */

#ifndef __RANDOMSTRATEGY_H__
#define __RANDOMSTRATEGY_H__

#include "Play.h"
#include "Strategy.h"

class Result;

/*
 * Class implements the random strategy, it always chooses randomly between cooperate and defect
 */
class RandomStrategy : public IStrategy
{
public:
    explicit RandomStrategy ();
    RandomStrategy (const RandomStrategy&) = delete;
    RandomStrategy (RandomStrategy&&) = default;

    virtual ~RandomStrategy () override = default;

    RandomStrategy& operator= (const RandomStrategy&) = delete;
    RandomStrategy& operator= (RandomStrategy&&) = default;

    virtual Play ChoosePlay () const override;
    virtual void NotifyResult (const Result& /* result */) override;
};

#endif
