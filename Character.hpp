#ifndef Character_H
#define Character_H

#include "GameObject.hpp"

class Character : public GameObject {
    private:
     int health;
     int bullet_timer;
    public:
     int &get_health();
     void set_health(int health);
     void set_bullet_timer(int timer);
     int &get_bullet_timer();
     virtual void fire() = 0;
};

#endif