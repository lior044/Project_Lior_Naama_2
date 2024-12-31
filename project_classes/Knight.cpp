#include "Knight.h"
int Knight::Invalid_move(int x_current, int y_current, int x_next, int y_next, char board[8][8]) {
    int Invalid = 1;
    int knight_moves[8][2] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < 8; ++i) {
        int x = x_current + knight_moves[i][0];
        int y = y_current + knight_moves[i][1];
        if (x >= 0 && x < 8 && y >= 0 && y < 8) {
            if (x == x_next && y == y_next) {
                Invalid = 0;
            }
        }
    }

    return Invalid;
}
