//
//  main.cpp
//  New Project 1
//
//  Created by Time Thief on 1/14/23.
//


#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>
#include <cctype>
#include "Game.h"

using namespace std;


///////////////////////////////////////////////////////////////////////////
// main()
///////////////////////////////////////////////////////////////////////////

int main()
{
      // Create a game
      // Use this instead to create a mini-game:   Game g(3, 5, 2);
    Game g(3, 5, 2);

      // Play the game
    g.play();
}

