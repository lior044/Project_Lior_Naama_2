#pragma once
#include <iostream>
#include <string>

#define WHITE 0
#define BLACK 1

using namespace std;

class Move_Log {
public:
	Move_Log();
	~Move_Log();

	int get_Check() const;
	int get_self_check() const;
	int get_Move_Invalid_Piece() const;
	int get_Move_to_self_piece() const;
	int get_Invalid_Index() const;
	int get_Move_To_Same_Index() const;
	int get_Invalid_move() const;

	void set_Check(const int set);
	void set_self_check(const int set);
	void set_Move_Invalid_Piece(const int set);
	void set_Move_to_self_piece(const int set);
	void set_Invalid_Index(const int set);
	void set_Move_To_Same_Index(const int set);
	void set_Invalid_move(const int set);



private:
	//if this on then still a valid play
	int _Check = 0;


	//if one of these are on then not a valid play
	int _Move_Invalid_Piece;
	int _Move_to_self_piece;
	int _self_check;
	int _Invalid_Index;
	int _Invalid_move;
	int _Move_To_Same_Index;

};