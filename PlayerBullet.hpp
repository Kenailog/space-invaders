#ifndef PlayerBullet_H
#define PlayerBullet_H

#include "Bullet.hpp"

class PlayerBullet : public Bullet {
    public:
     PlayerBullet();
     PlayerBullet(int x, int y, const char &symbol);
     void Move() override;
};

#endif