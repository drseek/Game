/*
 * Copyright (c) 2024 by Stefan Titze
 * 
 * This software is licensed under the MIT License. 
 * The full terms of the license can be found in the 'license' file included with this distribution.
 */

#include "AlwaysCooperate.h"

#include "Result.h"

AlwaysCooperate::AlwaysCooperate ()
    : IStrategy {"AlwaysCooperate"}
{}

Play AlwaysCooperate::ChoosePlay () const
{
    return Play::Cooperate;
}

void AlwaysCooperate::NotifyResult (const Result& /* result */)
{}
