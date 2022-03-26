#include <iostream>
#include <string>
#include "game.h"
#include "space.h"

namespace main_savitch_14{

    class Othello:public game{
        public:
            Othello();
            void make_move(const std::string& move);
            void restart();
            game* clone()const;
            void compute_moves(std::queue<std::string>& moves)const;
            void display_status()const;
            int evaluate()const;
            bool is_game_over()const;
            bool is_legal(const std::string& move)const;
            bool look_right(int y, int x)const;
            bool look_left(int y, int x)const;
            bool look_up(int y, int x)const;
            bool look_down(int y, int x)const;
            bool look_upleft(int y, int x)const;
            bool look_upright(int y, int x)const;
            bool look_downleft(int y, int x)const;
            bool look_downright(int y, int x)const;
            void flip_right(int y, int x);
            void flip_left(int y, int x);
            void flip_up(int y, int x);
            void flip_down(int y, int x);
            void flip_upleft(int y, int x);
            void flip_upright(int y, int x);
            void flip_downleft(int y, int x);
            void flip_downright(int y, int x);

        private:
            Space board[8][8];
            int total_moves;
    };
}