/*
 * Copyright (c) 2024 by Stefan Titze
 * 
 * This software is licensed under the MIT License. 
 * The full terms of the license can be found in the 'license' file included with this distribution.
 */

#ifndef __PLAY_H__
#define __PLAY_H__

#include <string_view>

enum class Play
{
    Cooperate,
    Defect
};

const std::string_view& to_string (const Play& play);

#endif
