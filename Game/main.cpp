/*
 * Copyright (c) 2024 by Stefan Titze
 * 
 * This software is licensed under the MIT License. 
 * The full terms of the license can be found in the 'license' file included with this distribution.
 */

#include <iostream>

#include "AlwaysCooperate.h"
#include "Game.h"
#include "GameResult.h"
#include "Play.h"
#include "RandomStrategy.h"
#include "Result.h"
#include "Score.h"
#include "Strategy.h"

using namespace std;

void PrintRound (const Result& result)
{
    cout << "Round " << result.GetRound () << endl;
    cout << result.GetFirstStrategy ()->GetName () << ": " << to_string (result.GetFirstPlay ()) << endl;
    cout << result.GetSecondStrategy ()->GetName () << ": " << to_string (result.GetSecondPlay ()) << endl;
    cout << result.GetFirstScore () << ':' << result.GetSecondScore () << endl;
    cout << endl;
}

void PrintWinner (const GameResult& result)
{
    if (shared_ptr<const IStrategy> winner {result.GetWinner ()})
        cout << "Winner is " << winner->GetName () << endl;
    else
        cout << "Draw" << endl;
    cout << result.GetFirstScore () << ':' << result.GetSecondScore () << endl;
}

int main ()
{
    Game<AlwaysCooperate, RandomStrategy, 10U> game;
    
    // setup callbacks
    game.RegisterNotifyRound (&PrintRound);
    game.RegisterNotifyGame (&PrintWinner);
    
    // start the game
    game.Play ();

    return 0;
}
