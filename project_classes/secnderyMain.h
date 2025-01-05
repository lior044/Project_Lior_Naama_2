#pragma once

#include <string> 
#include "Board.h" 

class SecondaryMain 
{
public:
    SecondaryMain( Board& my_board);
    ~SecondaryMain();
    // Function declaration with parameter types
    int gamefunc(const std::string& move);
    Board get_board() const;

private:
    std::string _Move; 
    Board My_Board;  
};
