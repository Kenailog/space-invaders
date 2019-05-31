#include "Enemy.hpp"

Enemy::Enemy(int &x, int &y, const char &symbol)
{
    this->set_x(x);
    this->set_y(y);
    this->set_symbol(symbol);
}

bool Enemy::is_in_map_area()
{
    return get_x() > 1 && get_x() < Screen::get_width() - 2 && get_y() > 1 && get_y() < Screen::get_height() * .5;
}

bool Enemy::can_move_right()
{
    return get_x() < Screen::get_width() - 2;
}

bool Enemy::can_move_left()
{
    return get_x() > 1;
}

bool Enemy::can_move_up()
{
    return get_y() > 1;
}

bool Enemy::can_move_down()
{
    return get_y() < Screen::get_height() * .6;
}

void Enemy::switch_direction()
{
    randomize_direction();
    switch (random_direction)
    {
    case 0:
        direction = STOP;
        break;
    case 1:
        direction = UP;
        break;
    case 2:
        direction = DOWN;
        break;
    case 3:
        direction = LEFT;
        break;
    case 4:
        direction = RIGHT;
        break;
    case 5:
        direction = LEFT_DOWN;
        break;
    case 6:
        direction = LEFT_UP;
        break;
    case 7:
        direction = RIGHT_DOWN;
        break;
    case 8:
        direction = RIGHT_UP;
        break;
    }
}

void Enemy::randomize_direction()
{
    random_direction = rand() % 9;
}

void Enemy::Move()
{
    switch (direction)
    {
    case DOWN:
        if (can_move_down())
        {
            set_y(get_y() + 1);
        }
        break;
    case UP:
        if (can_move_up())
        {
            set_y(get_y() - 1);
        }
        break;
    case LEFT:
        if (can_move_left())
        {
            set_x(get_x() - 1);
        }
        break;
    case RIGHT:
        if (can_move_right())
        {
            set_x(get_x() + 1);
        }
        break;
    case LEFT_DOWN:
        if (can_move_down() && can_move_left())
        {
            set_x(get_x() - 1);
            set_y(get_y() + 1);
        }
        break;
    case LEFT_UP:
        if (can_move_up() && can_move_left())
        {
            set_x(get_x() - 1);
            set_y(get_y() - 1);
        }
        break;
    case RIGHT_DOWN:
        if (can_move_down() && can_move_right())
        {
            set_x(get_x() + 1);
            set_y(get_y() + 1);
        }
        break;
    case RIGHT_UP:
        if (can_move_up() && can_move_right())
        {
            set_x(get_x() + 1);
            set_y(get_y() - 1);
        }
        break;
    case STOP:
        set_x(get_x());
        set_y(get_y());
        break;
    }

    // if (rand() % 2 == 0)
    // {
    //     for (size_t i = 0; i < rand() % 3; i++)
    //     {
    //         if (this->get_x() > 1)
    //         {
    //             this->set_x(this->get_x() - 1);
    //         }
    //         else
    //         {
    //             this->set_x(this->get_x());
    //         }
    //     }
    // }
    // else
    // {
    //     for (size_t i = 0; i < rand() % 3; i++)
    //     {
    //         if (this->get_x() < Screen::get_width() - 2)
    //         {
    //             this->set_x(this->get_x() + 1);
    //         }
    //         else
    //         {
    //             this->set_x(this->get_x());
    //         }
    //     }
    // }

    // if (rand() % 2 == 0)
    // {
    //     for (size_t i = 0; i < rand() % 3; i++)
    //     {
    //         if (this->get_y() > 1)
    //         {
    //             this->set_y(this->get_y() - 1);
    //         }
    //         else
    //         {
    //             this->set_y(this->get_y());
    //         }
    //     }
    // }
    // else
    // {
    //     for (size_t i = 0; i < rand() % 3; i++)
    //     {
    //         if (this->get_y() < Screen::get_height() * .5)
    //         {
    //             this->set_y(this->get_y() + 1);
    //         }
    //         else
    //         {
    //             this->set_y(this->get_y());
    //         }
    //     }
    // }
}

void Enemy::fire()
{
    this->bullet.set_position(this->get_x(), this->get_y() + 1);
    this->bullets.push_back(this->bullet);
}

EnemyBullet &Enemy::get_bullet()
{
    return this->bullet;
}

std::vector<EnemyBullet> &Enemy::get_bullets()
{
    return this->bullets;
}

int &Enemy::get_move_timer()
{
    return this->move_timer;
}

void Enemy::set_move_timer(int move_timer)
{
    this->move_timer = move_timer;
}