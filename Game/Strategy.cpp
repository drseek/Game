/*
 * Copyright (c) 2024 by Stefan Titze
 * 
 * This software is licensed under the MIT License. 
 * The full terms of the license can be found in the 'license' file included with this distribution.
 */

#include "Strategy.h"

using namespace std;

IStrategy::IStrategy (const string& name)
    : m_Name {name}
{}

const string& IStrategy::GetName () const
{
    return m_Name;
}
