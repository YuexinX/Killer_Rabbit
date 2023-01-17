//
//  Rabbit.hpp
//  New Project 1
//
//  Created by Time Thief on 1/14/23.
//

#ifndef Rabbit_h
#define Rabbit_h
#include "Arena.h"
#include "globals.h"
class Arena;

class Rabbit
{
  public:
      // Constructor
    Rabbit(Arena* ap, int r, int c);

      // Accessors
    int  row() const;
    int  col() const;
    bool isDead() const;

      // Mutators
    void move();

  private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    int    m_health;
    int    m_idleTurnsRemaining;
};

#endif /* Rabbit_hpp */
