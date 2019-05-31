#include "GameObject.hpp"

int GameObject::get_x() {
    return this->x;
}

void GameObject::set_x(int x) {
    this->x = x;
}

int GameObject::get_y() {
    return this->y;
}

void GameObject::set_y(int y) {
    this->y = y;
}

char GameObject::get_symbol() {
    return this->symbol;
}

void GameObject::set_symbol(char symbol) {
    this->symbol = symbol;
}