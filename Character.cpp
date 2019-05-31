#include "Character.hpp"

int &Character::get_health() {
    return this->health;
}

void Character::set_health(int health) {
    this->health = health;
}

void Character::set_bullet_timer(int timer) {
    this->bullet_timer = timer;
}

int &Character::get_bullet_timer() {
    return this->bullet_timer;
}