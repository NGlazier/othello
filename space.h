#include <iostream>
#include <string>
#include "game.h"



    class Space{
        public:
            Space();
            bool is_black()const;
            bool is_white()const;
            bool is_empty()const;
            void flip();
            void make_black();
            void make_white();
            void make_empty();
            void output(std::ostream& outs)const;
        private:
            char piece;
    };

    std::ostream& operator << (std::ostream& outs, const Space& s);
