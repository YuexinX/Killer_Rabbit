//
//  History.hpp
//  New Project 1
//
//  Created by Time Thief on 1/14/23.
//

#ifndef History_hpp
#define History_hpp
#include "globals.h"

class History
{
public:
    History(int nRows, int nCols);
    bool record(int r, int c);
    void display() const;
    
private:
    int h_nRows, h_nCols;
    int h_grid[MAXROWS][MAXCOLS];
};


#endif /* History_hpp */
