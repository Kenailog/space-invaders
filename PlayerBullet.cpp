#include "PlayerBullet.hpp"

PlayerBullet::PlayerBullet() {};

PlayerBullet::PlayerBullet(int x, int y, const char &symbol) { 
    this->set_position(x, y);
    this->set_symbol(symbol);
}

void PlayerBullet::Move() {   
    this->set_y(this->get_y() - 1);
}