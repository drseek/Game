/*
 * Copyright (c) 2024 by Stefan Titze
 * 
 * This software is licensed under the MIT License. 
 * The full terms of the license can be found in the 'license' file included with this distribution.
 */

#include "Play.h"

#include <stdexcept>

using namespace std;

const string_view& to_string (const Play& play)
{
    static const string_view cooperate {"Cooperate"};
    static const string_view defect {"Defect"};

    switch (play)
    {
    case Play::Cooperate:
        return cooperate;
    case Play::Defect:
        return defect;
    default:
        throw invalid_argument {"value of play is invalid"};
    }
}
