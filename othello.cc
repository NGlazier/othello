#include <iostream>
#include <string>
#include "game.h"
#include "othello.h"
#include "colors.h"

namespace main_savitch_14{

    Othello::Othello(){
        restart();
    }

    void Othello::restart(){
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                board[i][j].make_empty();
            }
        }
        board[3][3].make_black();
        board[4][4].make_black();
        board[3][4].make_white();
        board[4][3].make_white();
        total_moves = 0;
    }

    void Othello::display_status()const{
        if(total_moves % 2 == 0){
            cout << B_RED << WHITE << "You are X's.  Enter your move as A1" << B_BLACK << endl;
        }else{
            cout << B_RED << WHITE << "This is the computer's move" << B_BLACK << endl;
        }
        cout << B_BLACK << WHITE << "   1   2   3   4   5   6   7   8  " << endl;
        cout << B_BLACK << " " << B_GREEN << BLACK << " --------------------------------" << B_BLACK << WHITE << endl;
        cout << B_BLACK << WHITE << "A" << B_GREEN << BLACK << "| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " | " << board[0][3] << " | " << board[0][4] << " | " << board[0][5] << " | " << board[0][6] << " | " << board[0][7] << " |" << B_BLACK << WHITE << endl;
        cout << B_BLACK << " " << B_GREEN << BLACK << " --------------------------------" << B_BLACK << WHITE << endl;
        cout << B_BLACK << WHITE << "B" << B_GREEN << BLACK << "| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " | " << board[1][3] << " | " << board[1][4] << " | " << board[1][5] << " | " << board[1][6] << " | " << board[1][7] << " |" << B_BLACK << WHITE << endl;
        cout << B_BLACK << " " << B_GREEN << BLACK << " --------------------------------" << B_BLACK << WHITE << endl;
        cout << B_BLACK << WHITE << "C" << B_GREEN << BLACK << "| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " | " << board[2][3] << " | " << board[2][4] << " | " << board[2][5] << " | " << board[2][6] << " | " << board[2][7] << " |" << B_BLACK << WHITE << endl;
        cout << B_BLACK << " " << B_GREEN << BLACK << " --------------------------------" << B_BLACK << WHITE << endl;
        cout << B_BLACK << WHITE << "D" << B_GREEN << BLACK << "| " << board[3][0] << " | " << board[3][1] << " | " << board[3][2] << " | " << board[3][3] << " | " << board[3][4] << " | " << board[3][5] << " | " << board[3][6] << " | " << board[3][7] << " |" << B_BLACK << WHITE << endl;
        cout << B_BLACK << " " << B_GREEN << BLACK << " --------------------------------" << B_BLACK << WHITE << endl;
        cout << B_BLACK << WHITE << "E" << B_GREEN << BLACK << "| " << board[4][0] << " | " << board[4][1] << " | " << board[4][2] << " | " << board[4][3] << " | " << board[4][4] << " | " << board[4][5] << " | " << board[4][6] << " | " << board[4][7] << " |" << B_BLACK << WHITE << endl;
        cout << B_BLACK << " " << B_GREEN << BLACK << " --------------------------------" << B_BLACK << WHITE << endl;
        cout << B_BLACK << WHITE << "F" << B_GREEN << BLACK << "| " << board[5][0] << " | " << board[5][1] << " | " << board[5][2] << " | " << board[5][3] << " | " << board[5][4] << " | " << board[5][5] << " | " << board[5][6] << " | " << board[5][7] << " |" << B_BLACK << WHITE << endl;
        cout << B_BLACK << " " << B_GREEN << BLACK << " --------------------------------" << B_BLACK << WHITE << endl;
        cout << B_BLACK << WHITE << "G" << B_GREEN << BLACK << "| " << board[6][0] << " | " << board[6][1] << " | " << board[6][2] << " | " << board[6][3] << " | " << board[6][4] << " | " << board[6][5] << " | " << board[6][6] << " | " << board[6][7] << " |" << B_BLACK << WHITE << endl;
        cout << B_BLACK << " " << B_GREEN << BLACK << " --------------------------------" << B_BLACK << WHITE << endl;
        cout << B_BLACK << WHITE << "H" << B_GREEN << BLACK << "| " << board[7][0] << " | " << board[7][1] << " | " << board[7][2] << " | " << board[7][3] << " | " << board[7][4] << " | " << board[7][5] << " | " << board[7][6] << " | " << board[7][7] << " |" << B_BLACK << WHITE << endl;
        cout << B_BLACK << " " << B_GREEN << BLACK << " --------------------------------" << B_BLACK << WHITE << endl;
        cout << B_BLACK << WHITE << endl;
    }

    bool Othello::is_legal(const std::string& move)const{
        int y = (move[0] - 'A');
        int x = (move[1] - '1');
        if(y < 0 || y > 7 || x < 0 || x > 7){
            return false;
        }
        if(board[y][x].is_black() || board[y][x].is_white()){
            return false;
        }
        if(look_left(y, x) == true){
            return true;
        }
        if(look_right(y, x) == true){
            return true;
        }
        if(look_up(y, x) == true){
            return true;
        }
        if(look_down(y, x) == true){
            return true;
        }
        if(look_upleft(y, x) == true){
            return true;
        }
        if(look_upright(y, x) == true){
            return true;
        }
        if(look_downleft(y, x) == true){
            return true;
        }
        if(look_downright(y, x) == true){
            return true;
        }
        return false;
    }

    bool Othello::look_right(int y, int x)const{
        if(next_mover() == HUMAN){
            int i = x + 1;
            while(i <= 7 && board[y][i].is_white()){
                if(board[y][i+1].is_black()){
                    return true;
                }else{
                    i++;
                }
            }
            return false;
        }else{
            int i = x + 1;
            while(i <= 7 && board[y][i].is_black()){
                if(board[y][i+1].is_white()){
                    return true;
                }else{
                    i++;
                }
            }
            return false;
        }
    }

    bool Othello::look_down(int y, int x)const{
        if(next_mover() == HUMAN){
            int i = y + 1;
            while(i <= 7 && board[i][x].is_white()){
                if(board[i+1][x].is_black()){
                    return true;
                }else{
                    i++;
                }
            }
            return false;
        }else{
            int i = y + 1;
            while(i <= 7 && board[i][x].is_black()){
                if(board[i+1][x].is_white()){
                    return true;
                }else{
                    i++;
                }
            }
            return false;
        }
    }

    bool Othello::look_up(int y, int x)const{
        if(next_mover() == HUMAN){
            int i = y - 1;
            while(i >= 0 && board[i][x].is_white()){
                if(board[i-1][x].is_black()){
                    return true;
                }else{
                    i--;
                }
            }
            return false;
        }else{
            int i = y - 1;
            while(i >= 0 && board[i][x].is_black()){
                if(board[i-1][x].is_white()){
                    return true;
                }else{
                    i--;
                }
            }
            return false;
        }
    }

    bool Othello::look_left(int y, int x)const{
        if(next_mover() == HUMAN){
            int i = x - 1;
            while(i >= 0 && board[y][i].is_white()){
                if(board[y][i-1].is_black()){
                    return true;
                }else{
                    i--;
                }
            }
            return false;
        }else{
            int i = x - 1;
            while(i >= 0 && board[y][i].is_black()){
                if(board[y][i-1].is_white()){
                    return true;
                }else{
                    i--;
                }
            }
            return false;
        }
    }


    bool Othello::look_downright(int y, int x)const{
        if(next_mover() == HUMAN){
            int i = x + 1;
            int j = y + 1;
            while(i <= 7 && j <= 7 && board[j][i].is_white()){
                if(board[j+1][i+1].is_black()){
                    return true;
                }else{
                    i++;
                    j++;
                }
            }
            return false;
        }else{
            int i = x + 1;
            int j = y + 1;
            while(i <= 7 && j <= 7 && board[j][i].is_black()){
                if(board[j+1][i+1].is_white()){
                    return true;
                }else{
                    i++;
                    j++;
                }
            }
            return false;
        }
    }

    bool Othello::look_upleft(int y, int x)const{
        if(next_mover() == HUMAN){
            int i = x - 1;
            int j = y - 1;
            while(i >= 0 && j >=0 && board[j][i].is_white()){
                if(board[j-1][i-1].is_black()){
                    return true;
                }else{
                    i--;
                    j--;
                }
            }
            return false;
        }else{
            int i = x - 1;
            int j = y - 1;
            while(i >= 0 && j >= 0 && board[j][i].is_black()){
                if(board[j-1][i-1].is_white()){
                    return true;
                }else{
                    i--;
                    j--;
                }
            }
            return false;
        }
    }

    bool Othello::look_upright(int y, int x)const{
        if(next_mover() == HUMAN){
            int i = x + 1;
            int j = y - 1;
            while(i <= 7 && j >= 0 && board[j][i].is_white()){
                if(board[j-1][i+1].is_black()){
                    return true;
                }else{
                    i++;
                    j--;
                }
            }
            return false;
        }else{
            int i = x + 1;
            int j = y - 1;
            while(i <= 7 && j >= 0 && board[j][i].is_black()){
                if(board[j-1][i+1].is_white()){
                    return true;
                }else{
                    i++;
                    j--;
                }
            }
            return false;
        }
    }

      bool Othello::look_downleft(int y, int x)const{
        if(next_mover() == HUMAN){
            int i = x - 1;
            int j = y + 1;
            while(i >= 0 && j <= 7 && board[j][i].is_white()){
                if(board[j+1][i-1].is_black()){
                    return true;
                }else{
                    i--;
                    j++;
                }
            }
            return false;
        }else{
            int i = x - 1;
            int j = y + 1;
            while(i >= 0 && j <= 7 && board[j][i].is_black()){
                if(board[j+1][i-1].is_white()){
                    return true;
                }else{
                    i--;
                    j++;
                }
            }
            return false;
        }
    }

    void Othello::flip_right(int y, int x){
        if(next_mover() == HUMAN){
            int i = x + 1;
            while(board[y][i].is_white()){
                board[y][i].make_black();
                i++;
            }
        }else{
            int i = x + 1;
            while(board[y][i].is_black()){
                board[y][i].make_white();
                i++;
            }
        }
    }

    void Othello::flip_left(int y, int x){
        if(next_mover() == HUMAN){
            int i = x - 1;
            while(board[y][i].is_white()){
                board[y][i].make_black();
                i--;
            }
        }else{
            int i = x - 1;
            while(board[y][i].is_black()){
                board[y][i].make_white();
                i--;
            }
        }
    }

    void Othello::flip_up(int y, int x){
        if(next_mover() == HUMAN){
            int j = y - 1;
            while(board[j][x].is_white()){
                board[j][x].make_black();
                j--;
            }
        }
        else{
            int j = y - 1;
            while(board[j][x].is_black()){
                board[j][x].make_white();
                j--;
            }
        }
    }

    void Othello::flip_down(int y, int x){
        if(next_mover() == HUMAN){
            int j = y + 1;
            while(board[j][x].is_white()){
                board[j][x].make_black();
                j++;
            }
        }else{
            int j = y + 1;
            while(board[j][x].is_black()){
                board[j][x].make_white();
                j++;
            }
        }
    }

    void Othello::flip_upleft(int y, int x){
        if(next_mover() == HUMAN){
            int i = x - 1;
            int j = y - 1;
            while(board[j][i].is_white()){
                board[j][i].make_black();
                i--;
                j--;
            }
        }else{
            int i = x - 1;
            int j = y - 1;
            while(board[j][i].is_black()){
                board[j][i].make_white();
                i--;
                j--;
            }
        }
    }

    void Othello::flip_upright(int y, int x){
        if(next_mover() == HUMAN){
            int i = x + 1;
            int j = y - 1;
            while(board[j][i].is_white()){
                board[j][i].make_black();
                i++;
                j--;
            }
        }else{
            int i = x + 1;
            int j = y - 1;
            while(board[j][i].is_black()){
                board[j][i].make_white();
                i++;
                j--;
            }
        }
    }

     void Othello::flip_downleft(int y, int x){
        if(next_mover() == HUMAN){
            int i = x - 1;
            int j = y + 1;
            while(board[j][i].is_white()){
                board[j][i].make_black();
                i--;
                j++;
            }
        }else{
            int i = x - 1;
            int j = y + 1;
            while(board[j][i].is_black()){
                board[j][i].make_white();
                i--;
                j++;
            }
        }
    }

    void Othello::flip_downright(int y, int x){
        if(next_mover() == HUMAN){
            int i = x + 1;
            int j = y + 1;
            while(board[j][i].is_white()){
                board[j][i].make_black();
                i++;
                j++;
            }
        }else{
            int i = x + 1;
            int j = y + 1;
            while(board[j][i].is_black()){
                board[j][i].make_white();
                i++;
                j++;
            }
        }
    }


    void Othello::make_move(const std::string& move){

        if(is_legal(move) == true){
            int y = (move[0] - 'A');
            int x = (move[1] - '1');
            if(look_left(y, x) == true){
                flip_left(y, x);
            }
            if(look_right(y, x) == true){
                flip_right(y, x);
            }
            if(look_up(y, x) == true){
                flip_up(y, x);
            }
            if(look_down(y, x) == true){
                flip_down(y, x);
            }
            if(look_upleft(y, x) == true){
                flip_upleft(y, x);
            }
            if(look_upright(y, x) == true){
                flip_upright(y, x);
            }
            if(look_downleft(y, x) == true){
                flip_downleft(y, x);
            }
            if(look_downright(y, x) == true){
                flip_downright(y, x);
            }
            if(next_mover() == HUMAN){
                board[y][x].make_black();
            }
            if(next_mover() == COMPUTER){
                board[y][x].make_white();
            }
            total_moves++;
            game::make_move(move);
            
        }
    }

    void Othello::compute_moves(std::queue<std::string>& moves)const{
        for(char y = 'A'; y <= 'H'; y++){
            for(char x = '1'; x <= '8'; x++){
                string tmp = "  ";
                tmp[0] = y;
                tmp[1] = x;
                if(is_legal(tmp) == true){
                    moves.push(tmp);
                }
            }
        }
    }

    int Othello::evaluate()const{
        int computer_pieces = 0;
        int human_pieces = 0;
        for(int i = 0; i <= 7; i++){
            for(int j = 0; j <= 7; j++){
                if(board[i][j].is_black() == true){
                    human_pieces++;
                }
                if(board[i][j].is_white() == true){
                    computer_pieces++;
                }
            }
        }
        return (computer_pieces - human_pieces);
    }

    bool Othello::is_game_over()const{
        if(total_moves == 60){
            return true;
        }else{
            return false;
        }
    }

    game* Othello::clone()const{
        return new Othello(*this);
    }

}
