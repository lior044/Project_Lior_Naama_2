#include <iostream>
#include "King.h"

#define WHITE 0
#define BLACK 1
#define BOARD_SIZE 8

bool check_straight_line_threats(char Board[8][8], int king_x, int king_y, int turn);
bool check_diagonal_threats(char Board[8][8], int king_x, int king_y, int turn);
bool check_knight_threats(char Board[8][8], int king_x, int king_y, int turn);
bool check_pawn_threats(char Board[8][8], int king_x, int king_y, int turn);
bool check_king_threats(char Board[8][8], int king_x, int king_y, int turn);

int King::check_if_in_check(char Board[8][8], int turn) {
    int king_x = -1, king_y = -1;
    char king;
    if (turn == WHITE) {
        king = 'K';
    }
    else {
        king = 'k';
    }

    // Find the king's position
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (Board[i][j] == king) {
                king_x = j;
                king_y = i;
                break;
            }
        }
        if (king_x != -1) break; // Exit once the king is found
    }

    // Check all potential threats
    if (check_straight_line_threats(Board, king_x, king_y, turn) ||
        check_diagonal_threats(Board, king_x, king_y, turn) ||
        check_knight_threats(Board, king_x, king_y, turn) ||
        check_pawn_threats(Board, king_x, king_y, turn) ||
        check_king_threats(Board, king_x, king_y, turn)) {
        return 1; // King is in check
    }

    return 0; // King is not in check
}

// Helper Functions

bool check_straight_line_threats(char Board[8][8], int king_x, int king_y, int turn) {
    char rook;
    if (turn == WHITE) {
        rook = 'r';
    }
    else {
        rook = 'R';
    }
    char queen;
    if (turn == WHITE) {
        queen = 'q';
    }
    else {
        queen = 'Q';
    }

    // Check right
    for (int x = king_x + 1; x < BOARD_SIZE; ++x) {
        if (Board[king_y][x] != '#') {
            if (Board[king_y][x] == rook || Board[king_y][x] == queen) return true;
            break;
        }
    }
    // Check left
    for (int x = king_x - 1; x >= 0; --x) {
        if (Board[king_y][x] != '#') {
            if (Board[king_y][x] == rook || Board[king_y][x] == queen) return true;
            break;
        }
    }
    // Check down
    for (int y = king_y + 1; y < BOARD_SIZE; ++y) {
        if (Board[y][king_x] != '#') {
            if (Board[y][king_x] == rook || Board[y][king_x] == queen) return true;
            break;
        }
    }
    // Check up
    for (int y = king_y - 1; y >= 0; --y) {
        if (Board[y][king_x] != '#') {
            if (Board[y][king_x] == rook || Board[y][king_x] == queen) return true;
            break;
        }
    }

    return false;
}

bool check_diagonal_threats(char Board[8][8], int king_x, int king_y, int turn) {
    char bishop;
    if (turn == WHITE) {
        bishop = 'b';
    }
    else {
        bishop = 'B';
    }
    char queen;
    if (turn == WHITE) {
        queen = 'q';
    }
    else {
        queen = 'Q';
    }

    // Check top-right
    for (int x = king_x + 1, y = king_y - 1; x < BOARD_SIZE && y >= 0; ++x, --y) {
        if (Board[y][x] != '#') {
            if (Board[y][x] == bishop || Board[y][x] == queen) return true;
            break;
        }
    }
    // Check top-left
    for (int x = king_x - 1, y = king_y - 1; x >= 0 && y >= 0; --x, --y) {
        if (Board[y][x] != '#') {
            if (Board[y][x] == bishop || Board[y][x] == queen) return true;
            break;
        }
    }
    // Check bottom-right
    for (int x = king_x + 1, y = king_y + 1; x < BOARD_SIZE && y < BOARD_SIZE; ++x, ++y) {
        if (Board[y][x] != '#') {
            if (Board[y][x] == bishop || Board[y][x] == queen) return true;
            break;
        }
    }
    // Check bottom-left
    for (int x = king_x - 1, y = king_y + 1; x >= 0 && y < BOARD_SIZE; --x, ++y) {
        if (Board[y][x] != '#') {
            if (Board[y][x] == bishop || Board[y][x] == queen) return true;
            break;
        }
    }

    return false;
}

bool check_knight_threats(char Board[8][8], int king_x, int king_y, int turn) {
    char knight;
    if (turn == WHITE) {
        knight = 'n';
    }
    else {
        knight = 'N';
    }

    int knight_moves[8][2] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < 8; ++i) {
        int x = king_x + knight_moves[i][0];
        int y = king_y + knight_moves[i][1];
        if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE) {
            if (Board[y][x] == knight) return true;
        }
    }

    return false;
}

bool check_pawn_threats(char Board[8][8], int king_x, int king_y, int turn) {
    char pawn;
    if (turn == WHITE) {
        pawn = 'p';
    }
    else {
        pawn = 'P';
    }

    if (turn == WHITE) {
        if ((king_y > 0 && king_x > 0 && Board[king_y - 1][king_x - 1] == pawn) ||
            (king_y > 0 && king_x < 7 && Board[king_y - 1][king_x + 1] == pawn)) {
            return true;
        }
    }
    else {
        if ((king_y < 7 && king_x > 0 && Board[king_y + 1][king_x - 1] == pawn) ||
            (king_y < 7 && king_x < 7 && Board[king_y + 1][king_x + 1] == pawn)) {
            return true;
        }
    }

    return false;
}
bool check_king_threats(char Board[8][8], int king_x, int king_y, int turn) {
    char enemy_king;
    if (turn == WHITE) {
        enemy_king = 'k'; // Black king
    }
    else {
        enemy_king = 'K'; // White king
    }

    // Define all eight possible directions
    int directions[8][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}, // Horizontal and vertical
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1} // Diagonal
    };

    // Check each direction
    for (int i = 0; i < 8; i++) {
        int x = directions[i][0];
        int y = directions[i][1];
        int new_x = king_x + x;
        int new_y = king_y + y;

        // Check bounds and look for the enemy king in the first square in the direction
        if ((new_x >= 0 && new_x < 8 && new_y >= 0 && new_y < 8) && Board[new_y][new_x] == enemy_king) {
            return true;
        }
    }

    return false;
}

int King::Invalid_move(int x_current, int y_current, int x_next, int y_next) {
    int Invalid = 1;

    if ((x_current == x_next || x_current + 1 == x_next || x_current - 1 == x_next) && (y_current == y_next || y_current + 1 == y_next || y_current - 1 == y_next)) { //make sure that king only moved one step!
        Invalid = 0;
    }
    return Invalid;

}