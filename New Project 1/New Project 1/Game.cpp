//
//  Game.cpp
//  New Project 1
//
//  Created by Time Thief on 1/14/23.
//

#include "Game.h"
#include "History.h"
#include "Arena.h"
#include "Player.h"
#include "Rabbit.h"
#include <iostream>
#include <string>

///////////////////////////////////////////////////////////////////////////
//  Game implementation
///////////////////////////////////////////////////////////////////////////

Game::Game(int rows, int cols, int nRabbits)
{
    if (nRabbits < 0)
    {
        std::cout << "***** Cannot create Game with negative number of rabbits!" << std::endl;
        exit(1);
    }
    if (nRabbits > MAXRABBITS)
    {
        std::cout << "***** Trying to create Game with " << nRabbits
             << " rabbits; only " << MAXRABBITS << " are allowed!" << std::endl;
        exit(1);
    }
    int nEmpty = rows * cols - nRabbits - 1;  // 1 for Player
    if (nEmpty < 0)
    {
        std::cout << "***** Game created with a " << rows << " by "
             << cols << " arena, which is too small to hold a player and "
             << nRabbits << " rabbits!" << std::endl;
        exit(1);
    }

      // Create arena
    m_arena = new Arena(rows, cols);

      // Add player
    int rPlayer;
    int cPlayer;
    do
    {
        rPlayer = randInt(1, rows);
        cPlayer = randInt(1, cols);
    } while (m_arena->getCellStatus(rPlayer, cPlayer) != EMPTY);
    m_arena->addPlayer(rPlayer, cPlayer);

      // Populate with rabbits
    while (nRabbits > 0)
    {
        int r = randInt(1, rows);
        int c = randInt(1, cols);
        if (r == rPlayer && c == cPlayer)
            continue;
        m_arena->addRabbit(r, c);
        nRabbits--;
    }
}

Game::~Game()
{
    delete m_arena;
}

std::string Game::takePlayerTurn()
{
    for (;;)
    {
        std::cout << "Your move (n/e/s/w/c/h or nothing): ";
        std::string playerMove;
        getline(std::cin, playerMove);
        

        Player* player = m_arena->player();
        History& gameHistory = m_arena->history();
        g_callHistory = 0;
        int dir;

        if (playerMove.size() == 0)
        {
            if (recommendMove(*m_arena, player->row(), player->col(), dir))
                return player->move(dir);
            else
                return player->dropPoisonedCarrot();
        }
        else if (playerMove.size() == 1)
        {
            if (tolower(playerMove[0]) == 'c')
            {
                return player->dropPoisonedCarrot();
            }
            
            else if (decodeDirection(playerMove[0], dir))
                return player->move(dir);
        }
        if (playerMove.size() == 1 && tolower(playerMove[0])== 'h')
        {
            gameHistory.display();
            g_callHistory = 1;
            std::cout<<"Press enter to continue.";
            std::cin.ignore(10000,'\n');
            return "";
        }
        std::cout << "Player move must be nothing, or 1 character n/e/s/w/c." << std::endl;
    }
}

void Game::play()
{
    m_arena->display("");
    Player* player = m_arena->player();
    if (player == nullptr)
        return;
    while ( ! player->isDead()  &&  m_arena->rabbitCount() > 0)
    {
        std::string msg = takePlayerTurn();
        m_arena->display(msg);
        if (player->isDead())
            break;
        if(g_callHistory != 1)
        {
            m_arena->moveRabbits();
            m_arena->display(msg);
        }
    }
    if (player->isDead())
        std::cout << "You lose." << std::endl;
    else
        std::cout << "You win." << std::endl;
}

bool recommendMove(const Arena& a, int r, int c, int& bestDir)
{
      // How dangerous is it to stand?
    int standDanger = computeDanger(a, r, c);

      // if it's not safe, see if moving is safer
    if (standDanger > 0)
    {
        int bestMoveDanger = standDanger;
        int bestMoveDir = NORTH;  // arbitrary initialization

          // check the four directions to see if any move is
          // better than standing, and if so, record the best
        for (int dir = 0; dir < NUMDIRS; dir++)
        {
            int rnew = r;
            int cnew = c;
            if (attemptMove(a, dir, rnew, cnew))
            {
                int danger = computeDanger(a, rnew, cnew);
                if (danger < bestMoveDanger)
                {
                    bestMoveDanger = danger;
                    bestMoveDir = dir;
                }
            }
        }

          // if moving is better than standing, recommend move
        if (bestMoveDanger < standDanger)
        {
            bestDir = bestMoveDir;
            return true;
        }
    }
    return false;  // recommend standing
}
