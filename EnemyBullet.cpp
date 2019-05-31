#include "EnemyBullet.hpp"

EnemyBullet::EnemyBullet() {};

EnemyBullet::EnemyBullet(int &x, int &y, char &symbol) { 
    this->set_position(x, y);
    this->set_symbol(symbol);
}

void EnemyBullet::Move() {
    this->set_y(this->get_y() + 1);
}