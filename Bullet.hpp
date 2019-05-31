#ifndef Bullet_H
#define Bullet_H

#include "GameObject.hpp"

class Bullet : public GameObject {
    public:
     Bullet();
     void set_position(int x, int y);
};

#endif