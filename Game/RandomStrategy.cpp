/*
 * Copyright (c) 2024 by Stefan Titze
 * 
 * This software is licensed under the MIT License. 
 * The full terms of the license can be found in the 'license' file included with this distribution.
 */

#include "RandomStrategy.h"

#include <random>

#include "Result.h"

using namespace std;

RandomStrategy::RandomStrategy ()
    : IStrategy {"RandomStrategy"}
{}

Play RandomStrategy::ChoosePlay () const
{
    // static random generator
    static random_device device;
    static mt19937 generator {device ()};
    static uniform_int_distribution distribution {0, 1};

    if (0 == distribution (generator))
        return Play::Cooperate;
    return Play::Defect;
}

void RandomStrategy::NotifyResult (const Result& /* result */)
{}
