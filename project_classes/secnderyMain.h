#pragma once

#include <string> 
#include "Board.h" 

class SecondaryMain 
{
public:
    SecondaryMain(const std::string& move, Board& my_board);
    ~SecondaryMain();
    // Function declaration with parameter types
    std::string gamefunc(int x_current, int y_current, int x_next, int y_next);

private:
    std::string _Move; 
    Board My_Board;  
};
