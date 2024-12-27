#pragma once
#define WHITE 0
#define BLACK 1
#define BOARD_SIZE 8
#include <iostream>

class King {
public:
	static int check_if_in_mate(char Board[8][8], int turn);
	static int Invalid_move(int x_current, int y_current, int x_next, int y_next, char board[8][8]);
};
