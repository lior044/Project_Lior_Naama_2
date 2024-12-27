#include "Move_Log.h"
////if this 1 then still a valid play
//int _Check;
//
////if one of these are on then not a valid play
//int Move_Invalid_Piece;
//int Move_to_self_piece;
//int self_check;
//int Invalid_Index;
//int Invalid_move;
//int Move_To_Same_Index;

Move_Log::Move_Log() {
	//if this 1 then still a valid play
	_Check = 0;

	//if one of these are on then not a valid play
	_Move_Invalid_Piece = 0;
	_Move_to_self_piece = 0;
	_self_check = 0;
	_Invalid_Index = 0;
	_Invalid_move = 0;
	_Move_To_Same_Index = 0;
}
Move_Log::~Move_Log() {}

int Move_Log::get_Check() const {
	return _Check;
}
int Move_Log::get_self_check() const {
	return _self_check;
}
int Move_Log::get_Move_Invalid_Piece() const {
	return _Move_Invalid_Piece;
}
int Move_Log::get_Move_to_self_piece() const {
	return _Move_to_self_piece;
}
int Move_Log::get_Invalid_Index() const {
	return _Invalid_Index;
}
int Move_Log::get_Move_To_Same_Index() const {
	return _Move_To_Same_Index;
}
int Move_Log::get_Invalid_move() const {
	return _Invalid_move;
}

void Move_Log::set_Check(const int set) {
	_Check = set;
}
void Move_Log::set_self_check(const int set) {
	_self_check = set;
}
void Move_Log::set_Move_Invalid_Piece(const int set) {
	_Move_Invalid_Piece = set;
}
void Move_Log::set_Move_to_self_piece(const int set) {
	_Move_to_self_piece = set;
}
void Move_Log::set_Invalid_Index(const int set) {
	_Invalid_Index = set;
}
void Move_Log::set_Move_To_Same_Index(const int set) {
	_Move_To_Same_Index = set;
}
void Move_Log::set_Invalid_move(const int set) {
	_Invalid_move = set;
}

