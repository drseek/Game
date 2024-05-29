/*
 * Copyright (c) 2024 by Stefan Titze
 * 
 * This software is licensed under the MIT License. 
 * The full terms of the license can be found in the 'license' file included with this distribution.
 */

#ifndef __STRATEGY_H__
#define __STRATEGY_H__

#include <concepts>
#include <string>

#include "Play.h"

/* interface */ class IStrategy;

/*
 * Strategy concept, this concept is used to be able to construct concrete strategy
 * implementations and to ensure that those concrete implementations inherit from IStrategy
 */
template<typename T>
concept Strategy =
        std::derived_from<T, IStrategy>
    &&
        std::default_initializable<T>;

class Result;

/*
 * Strategy interface
 */
/* interface */ class IStrategy
{
private:
    std::string m_Name;

public:
    explicit IStrategy (const std::string& name);
    IStrategy (const IStrategy&) = delete;
    explicit IStrategy (IStrategy&&) = default;
    virtual ~IStrategy () = default;

    IStrategy& operator= (const IStrategy&) = delete;
    IStrategy& operator= (IStrategy&&) = default;

    const std::string& GetName () const;

    // Once per round the strategy can choose to either cooperate or defect. The Game object calls this method once for each round
    virtual Play ChoosePlay () const = 0;

    // Callback handler that will be called after each game round to inform the strategy about the result of the round
    virtual void NotifyResult (const Result& result) = 0;
};

#endif
