#ifndef Player_H
#define Player_H

#include "PlayerBullet.hpp"
#include "Character.hpp"
#include <conio.h>

class Player : public Character {
    private:
     enum direction { STOP = 0, LEFT, RIGHT };
     direction dir;
     int score = 0;
     PlayerBullet bullet;
     std::vector<PlayerBullet> bullets;
    public:
     Player(int x, int y, char symbol);
     void input();
     void Move() override;
     void fire() override;
     int &get_score();
     void set_score(int score);
     PlayerBullet &get_bullet();
     std::vector<PlayerBullet> &get_bullets();
};

#endif