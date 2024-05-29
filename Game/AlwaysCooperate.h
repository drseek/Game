/*
 * Copyright (c) 2024 by Stefan Titze
 * 
 * This software is licensed under the MIT License. 
 * The full terms of the license can be found in the 'license' file included with this distribution.
 */

#ifndef __ALWAYSCOOPERATE_H__
#define __ALWAYSCOOPERATE_H__

#include "Play.h"
#include "Strategy.h"

class Result;

/*
 * Class implements the always cooperate strategy, it always chooses cooperate
 */
class AlwaysCooperate : public IStrategy
{
public:
    explicit AlwaysCooperate ();
    AlwaysCooperate (const AlwaysCooperate&) = delete;
    AlwaysCooperate (AlwaysCooperate&&) = default;

    virtual ~AlwaysCooperate () override = default;

    AlwaysCooperate& operator= (const AlwaysCooperate&) = delete;
    AlwaysCooperate& operator= (AlwaysCooperate&&) = default;

    virtual Play ChoosePlay () const override;
    virtual void NotifyResult (const Result& /* result */) override;
};

#endif
