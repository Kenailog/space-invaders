#include "Player.hpp"
#include "GameStateManager.hpp"

Player::Player(int x, int y, char symbol)
{
    this->set_x(x);
    this->set_y(y);
    this->set_symbol(symbol);
}

void Player::input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            this->dir = LEFT;
            break;
        case 'd':
            this->dir = RIGHT;
            break;
        case 's':
            this->dir = STOP;
            break;
        case 'w':
            this->fire();
            break;
        case 'x':
            GameStateManager::isOver = true;
            break;
        }
    }
}

void Player::Move()
{
    switch (this->dir)
    {
    case LEFT:
        this->set_x(this->get_x() - 1);
        break;
    case RIGHT:
        this->set_x(this->get_x() + 1);
        break;
    default:
        break;
    }
    // this->set_x(this->get_x());
    // this->set_y(this->get_y());
}

void Player::fire()
{
    if (this->get_bullet_timer() == 0)
    {
        this->bullet.set_position(this->get_x(), this->get_y() - 1);
        this->bullets.push_back(this->bullet);
        this->set_bullet_timer(2);
    }
}

PlayerBullet &Player::get_bullet()
{
    return this->bullet;
}

std::vector<PlayerBullet> &Player::get_bullets()
{
    return this->bullets;
}

int &Player::get_score()
{
    return this->score;
}

void Player::set_score(int score)
{
    this->score = score;
}