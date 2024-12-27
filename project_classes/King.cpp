#include "King.h"

int King::check_if_in_mate(char Board[8][8], int turn) {
    int will_be_in_check = 0;
    char king;
    int king_x = NULL;
    int king_y = NULL;

    //init king char with correct color
    if (turn == WHITE) {
        king = 'K'; //white
    }
    else {
        king = 'k'; //black
    }

    //find king on Board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (Board[i][j] == king) {
                king_x = i;
                king_y = j;
                break;
            }
        }
        if (king_x != NULL) {
            break;
        }
    }

    // check all directions
    for (int i = king_x; i < 8; i++) { //check right _-  for queen or rook
        if (i != king_x) { //make sure it skips king`s index
            if (Board[king_y][i] != '#') {
                if (turn == WHITE) {
                    if (Board[king_y][i] == 'q' || Board[king_y][i] == 'r') {
                        will_be_in_check = 1;
                        break;
                    }
                    else {
                        break;
                    }
                }
                else {
                    if (Board[king_y][i] == 'Q' || Board[king_y][i] == 'R') {
                        will_be_in_check = 1;
                        break;
                    }
                    else {
                        break;
                    }
                }
            }
        }

    }


    for (int i = king_x; i >= 0; i--) { //check left -_ for queen or rook
        if (i != king_x) { //make sure it skips king`s index
            if (Board[king_y][i] != '#') {
                if (turn == WHITE) {
                    if (Board[king_y][i] == 'q' || Board[king_y][i] == 'r') {
                        will_be_in_check = 1;
                        break;
                    }
                    else {
                        break;
                    }
                }
                else {
                    if (Board[king_y][i] == 'Q' || Board[king_y][i] == 'R') {
                        will_be_in_check = 1;
                        break;
                    }
                    else {
                        break;
                    }
                }
            }
        }

    }

    for (int i = king_y; i < 8; i++) { //check down -| for queen or rook
        if (i != king_y) {  //make sure it skips king`s index
            if (Board[i][king_x] != '#') {
                if (turn == WHITE) {
                    if (Board[i][king_x] == 'q' || Board[i][king_x] == 'r') {
                        will_be_in_check = 1;
                        break;
                    }
                    else {
                        break;
                    }
                }
                else {
                    if (Board[i][king_x] == 'Q' || Board[i][king_x] == 'R') {
                        will_be_in_check = 1;
                        break;
                    }
                    else {
                        break;
                    }
                }
            }
        }

    }

    for (int i = king_y; i >= 0; i--) { //check up _| for queen or rook
        if (i != king_y) { //make sure it skips king`s index
            if (Board[i][king_x] != '#') {
                if (turn == WHITE) {
                    if (Board[i][king_x] == 'q' || Board[i][king_x] == 'r') {
                        will_be_in_check = 1;
                        break;
                    }
                    else {
                        break;
                    }
                }
                else {
                    if (Board[i][king_x] == 'Q' || Board[i][king_x] == 'R') {
                        will_be_in_check = 1;
                        break;
                    }
                    else {
                        break;
                    }
                }
            }
        }

    }

    for (int x = king_x, y = king_y; x < 8 && y >= 0; x++, y--) {  //check diagonal top right _/ for queen or bishop, or pawn if king white
        if (x != king_x && y != king_y) { //make sure it skips king`s index
            if (Board[y][x] != '#') {
                if (turn == WHITE) {
                    if (Board[king_y - 1][king_x + 1] == 'p') { //check pawn only if it is one step away
                        will_be_in_check = 1;
                    }
                    if (Board[y][x] == 'q' || Board[y][x] == 'b') {
                        will_be_in_check = 1;
                        break;
                    }
                    else {
                        break;
                    }
                }
                else {

                    if (Board[y][x] == 'Q' || Board[y][x] == 'B') {
                        will_be_in_check = 1;
                        break;
                    }
                    else {
                        break;
                    }
                }
            }
        }

    }

    for (int x = king_x, y = king_y; x >= 0 && y >= 0; x--, y--) {  //check diagonal top left \_ for queen or bishop, or pawn if king white
        if (x != king_x && y != king_y) { //make sure it skips king`s index
            if (Board[y][x] != '#') {
                if (turn == WHITE) {
                    if (Board[king_y - 1][king_x - 1] == 'p') { //check pawn only if it is one step away
                        will_be_in_check = 1;
                    }
                    if (Board[y][x] == 'q' || Board[y][x] == 'b') {
                        will_be_in_check = 1;
                        break;
                    }
                    else {
                        break;
                    }
                }
                else {

                    if (Board[y][x] == 'Q' || Board[y][x] == 'B') {
                        will_be_in_check = 1;
                        break;
                    }
                    else {
                        break;
                    }
                }
            }
        }

    }

    for (int x = king_x, y = king_y; x >= 0 && y < 8; x--, y++) {  //check diagonal bottom left /- for queen or bishop, or pawn if king is black
        if (x != king_x && y != king_y) { //make sure it skips king`s index
            if (Board[y][x] != '#') {
                if (turn == WHITE) {
                    if (Board[y][x] == 'q' || Board[y][x] == 'b') {
                        will_be_in_check = 1;
                        break;
                    }
                    else {
                        break;
                    }
                }
                else {
                    if (Board[king_y + 1][king_x - 1] == 'P') { //check pawn only if it is one step away
                        will_be_in_check = 1;
                        break;
                    }
                    if (Board[y][x] == 'Q' || Board[y][x] == 'B') {
                        will_be_in_check = 1;
                        break;
                    }
                    else {
                        break;
                    }
                }
            }
        }

    }

    for (int x = king_x, y = king_y; x < 8 && y < 8; x++, y++) {  //check diagonal bottom right -\ for queen or bishop or pawn if king is black
        if (x != king_x && y != king_y) { //make sure it skips king`s index
            if (Board[y][x] != '#') {
                if (turn == WHITE) {
                    if (Board[y][x] == 'q' || Board[y][x] == 'b') {
                        will_be_in_check = 1;
                        break;
                    }
                    else {
                        break;
                    }
                }
                else {
                    if (Board[king_y++][king_x++] == 'P') { //check pawn only if it is one step away
                        will_be_in_check = 1;
                        break;
                    }
                    if (Board[y][x] == 'Q' || Board[y][x] == 'B') {
                        will_be_in_check = 1;
                        break;
                    }
                    else {
                        break;
                    }
                }
            }
        }

    }

    //check all knight threats
    if (king_x + 2 < 8 && king_y + 1 < 8) {
        if (turn == WHITE) {
            if (Board[king_y + 1][king_x + 2] == 'n') {
                will_be_in_check = 1;
            }

        }
        else {
            if (Board[king_y + 1][king_x + 2] == 'N') {
                will_be_in_check = 1;
            }
        }
    }
    if (king_x + 1 < 8 && king_y + 2 < 8) {
        if (turn == WHITE) {
            if (Board[king_y + 2][king_x + 1] == 'n') {
                will_be_in_check = 1;
            }
        }
        else {
            if (Board[king_y + 2][king_x + 1] == 'N') {
                will_be_in_check = 1;
            }
        }
    }
    if (king_x - 2 >= 0 && king_y + 1 < 8) {
        if (turn == WHITE) {
            if (Board[king_y + 1][king_x - 2] == 'n') {
                will_be_in_check = 1;
            }
        }
        else {
            if (Board[king_y + 1][king_x - 2] == 'N') {
                will_be_in_check = 1;
            }
        }
    }
    if (king_x - 1 >= 0 && king_y + 2 < 8) {
        if (turn == WHITE) {
            if (Board[king_y + 2][king_x - 1] == 'n') {
                will_be_in_check = 1;
            }
        }
        else {
            if (Board[king_y + 2][king_x - 1] == 'N') {
                will_be_in_check = 1;
            }
        }
    }
    if (king_x + 2 < 8 && king_y - 1 >= 0) {
        if (turn == WHITE) {
            if (Board[king_y - 1][king_x + 2] == 'n') {
                will_be_in_check = 1;
            }
        }
        else {
            if (Board[king_y - 1][king_x + 2] == 'N') {
                will_be_in_check = 1;
            }
        }
    }
    if (king_x + 1 < 8 && king_y - 2 >= 0) {
        if (turn == WHITE) {
            if (Board[king_y - 2][king_x + 1] == 'n') {
                will_be_in_check = 1;
            }
        }
        else {
            if (Board[king_y - 2][king_x + 1] == 'N') {
                will_be_in_check = 1;
            }
        }
    }
    if (king_x - 2 >= 0 && king_y - 1 >= 0) {
        if (turn == WHITE) {
            if (Board[king_y - 1][king_x - 2] == 'n') {
                will_be_in_check = 1;
            }
        }
        else {
            if (Board[king_y - 1][king_x - 2] == 'N') {
                will_be_in_check = 1;
            }
        }
    }
    if (king_x - 1 >= 0 && king_y - 2 >= 0) {
        if (turn == WHITE) {
            if (Board[king_y - 2][king_x - 1] == 'n') {
                will_be_in_check = 1;
            }
        }
        else {
            if (Board[king_y - 2][king_x - 1] == 'N') {
                will_be_in_check = 1;

            }
        }
    }

    return will_be_in_check;
}





