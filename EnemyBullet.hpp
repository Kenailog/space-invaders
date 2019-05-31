#ifndef EnemyBullet_H
#define EnemyBullet_H

#include "Bullet.hpp"

class EnemyBullet : public Bullet {
    public:
     EnemyBullet();
     EnemyBullet(int &x, int &y, char &symbol);
     void Move() override;
};

#endif