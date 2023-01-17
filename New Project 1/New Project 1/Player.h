//
//  Player.hpp
//  New Project 1
//
//  Created by Time Thief on 1/14/23.
//

#ifndef Player_hpp
#define Player_hpp
#include "Arena.h"
#include "globals.h"
class Player
{
  public:
      // Constructor
    Player(Arena* ap, int r, int c);

      // Accessors
    int  row() const;
    int  col() const;
    bool isDead() const;

      // Mutators
    string dropPoisonedCarrot();
    string move(int dir);
    void   setDead();

  private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    bool   m_dead;
};


#endif /* Player_hpp */
