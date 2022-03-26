#include <iostream>
#include <string>
#include "game.h"
#include "space.h"



    Space::Space(){
        piece = ' ';
    }

    bool Space::is_black()const{
        if(piece == 'X'){
            return true;
        }else{
            return false;
        }
    }

    bool Space::is_white()const{
        if(piece == 'O'){
            return true;
        }else{
            return false;
        }
    }

    bool Space::is_empty()const{
        if(piece == ' '){
            return true;
        }else{
            return false;
        }
    }

    void Space::make_black(){
        piece = 'X';
    }

    void Space::make_white(){
        piece = 'O';
    }

    void Space::make_empty(){
        piece = ' ';
    }

    void Space::flip(){
        if(is_black() == true){
            make_white();
        }
        
        if(is_white() == true){
            make_black();
        }
    }

    void Space::output(std::ostream& outs)const{
        outs << piece;
    }
    
    std::ostream& operator << (std::ostream& outs, const Space& s){
        s.output(outs);
        return outs;
    }