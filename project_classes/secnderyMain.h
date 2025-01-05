#pragma once

#include <string> 
#include "Board.h" 

class SecondaryMain 
{
public:
    // Function declaration with parameter types
    std::string gamefunc(const std::string& move, const Board& my_board,  int x_current, int y_current, int x_next, int y_next);

private:
    std::string move; 
    Board my_board;  
    int x_current;
    int y_current;
    int x_next;
    int y_next;
};
