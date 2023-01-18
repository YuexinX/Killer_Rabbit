//
//  History.cpp
//  New Project 1
//
//  Created by Time Thief on 1/14/23.
//

#include "History.h"
#include "Arena.h"
#include <iostream>
History::History(int nRows, int nCols)
{
    h_nRows = nRows;
    h_nCols = nCols;
    //construct an empty arena that has nRows and nCols
    for(int r = 1; r <= nRows ; r++)
    {
        for(int c = 1; c <= nCols; c++)
        {
            h_grid[r-1][c-1] = 0;
        }
    }
}

bool History::record(int r, int c)
{
    //notify History that a carrot has been dropped at a grid point that does not currently have a poisoned carrot
    //return false if row r, column c is not within the bounds
    if(h_nCols< c || h_nRows < r || c<1 || r<1)
        return false;
    else
        h_grid[r-1][c-1]++;
        return true;
}

void History::display() const
{
    clearScreen();
    char displayGrid[MAXROWS][MAXCOLS];
    int r,c;
    for(r=1;r<=h_nRows;r++)
    {
        for(c=1;c<=h_nCols;c++)
        {
            if(h_grid[r-1][c-1]==0)
                displayGrid[r-1][c-1] = '.';
            else
            {
                int numberPut = h_grid[r-1][c-1];
                switch(numberPut)
                {
                    case 1:
                        displayGrid[r-1][c-1] = 'A';
                        break;
                    case 2:
                        displayGrid[r-1][c-1] = 'B';
                        break;
                    case 3:
                        displayGrid[r-1][c-1] = 'C';
                        break;
                    case 4:
                        displayGrid[r-1][c-1] = 'D';
                        break;
                    case 5:
                        displayGrid[r-1][c-1] = 'E';
                        break;
                    case 6:
                        displayGrid[r-1][c-1] = 'F';
                        break;
                    case 7:
                        displayGrid[r-1][c-1] = 'G';
                        break;
                    case 8:
                        displayGrid[r-1][c-1] = 'H';
                        break;
                    case 9:
                        displayGrid[r-1][c-1] = 'I';
                        break;
                    case 10:
                        displayGrid[r-1][c-1] = 'J';
                        break;
                    case 11:
                        displayGrid[r-1][c-1] = 'K';
                        break;
                    case 12:
                        displayGrid[r-1][c-1] = 'L';
                        break;
                    case 13:
                        displayGrid[r-1][c-1] = 'M';
                        break;
                    case 14:
                        displayGrid[r-1][c-1] = 'N';
                        break;
                    case 15:
                        displayGrid[r-1][c-1] = 'O';
                        break;
                    case 16:
                        displayGrid[r-1][c-1] = 'P';
                        break;
                    case 17:
                        displayGrid[r-1][c-1] = 'Q';
                        break;
                    case 18:
                        displayGrid[r-1][c-1] = 'R';
                        break;
                    case 19:
                        displayGrid[r-1][c-1] = 'S';
                        break;
                    case 20:
                        displayGrid[r-1][c-1] = 'T';
                        break;
                    case 21:
                        displayGrid[r-1][c-1] = 'U';
                        break;
                    case 22:
                        displayGrid[r-1][c-1] = 'V';
                        break;
                    case 23:
                        displayGrid[r-1][c-1] = 'W';
                        break;
                    case 24:
                        displayGrid[r-1][c-1] = 'X';
                        break;
                    case 25:
                        displayGrid[r-1][c-1] = 'Y';
                        break;
                    case 26:
                        displayGrid[r-1][c-1] = 'Z';
                        break;
                    default:
                        displayGrid[r-1][c-1] = 'Z';
                        break;
                }
            }
        }
        
    }
    //clear the screen, display the history grid, write an empty line after the history grid
    for(r=1;r<=h_nRows;r++)
    {
        for(c=1;c<=h_nCols;c++)
        {
            std::cout<<displayGrid[r-1][c-1];
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    
}
