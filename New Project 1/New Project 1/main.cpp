//
//  main.cpp
//  New Project 1
//
//  Created by Time Thief on 1/14/23.
//

/*
#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>
#include <cctype>
#include "globals.h"
#include "Game.h"

using namespace std;



///////////////////////////////////////////////////////////////////////////
// Type definitions
///////////////////////////////////////////////////////////////////////////

class Arena;  // This is needed to let the compiler know that Arena is a
              // type name, since it's mentioned in the Rabbit declaration.





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
*/
#include "Arena.h"
    #include "Player.h"
    #include "History.h"
    #include "globals.h"
    #include <iostream>
    using namespace std;

    int main()
    {
        Arena a(1, 4);
        a.addPlayer(1, 2);
        a.player()->dropPoisonedCarrot();
        a.player()->dropPoisonedCarrot();
        a.player()->move(EAST);
        a.player()->dropPoisonedCarrot();
        a.player()->move(EAST);
        a.addRabbit(1, 1);
        while (a.rabbitCount() > 0)
            a.moveRabbits();
        a.player()->move(WEST);
        a.player()->dropPoisonedCarrot();
        a.history().display();
        cout << "====" << endl;
    }
