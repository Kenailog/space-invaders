#ifndef GameObject_H
#define GameObject_H

#include <vector>

class GameObject {
    private:
        int x;
        int y;
        char symbol;
    public:
        // static std::vector<GameObject*> game_objects;
        virtual void Move() = 0;
        int get_x();             
        void set_x(int x);        
        int get_y();       
        void set_y(int y);
        char get_symbol();
        void set_symbol(char symbol);
};

#endif