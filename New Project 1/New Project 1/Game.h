//
//  Game.hpp
//  New Project 1
//
//  Created by Time Thief on 1/14/23.
//

#ifndef Game_hpp
#define Game_hpp
#include "Arena.h"
#include <string>

class Game
{
  public:
      // Constructor/destructor
    Game(int rows, int cols, int nRabbits);
    ~Game();

      // Mutators
    void play();

  private:
    Arena* m_arena;

      // Helper functions
    std::string takePlayerTurn();
};

#endif /* Game_hpp */
