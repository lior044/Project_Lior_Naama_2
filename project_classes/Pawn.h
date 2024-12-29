#pragma once
#define WHITE 0
#define BLACK 1

class Pawn {
public:
	static int Invalid_move(int x_current, int y_current, int x_next, int y_next, char board[8][8]);
};