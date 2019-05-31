#ifndef Enemy_H
#define Enemy_H

#include <ctime>
#include <cstdlib>

#include "Character.hpp"
#include "EnemyBullet.hpp"
#include "Screen.hpp"

class Enemy : public Character
{
  private:
    int move_timer;
    enum Direction
    {
        STOP = 0,
        UP,
        DOWN,
        LEFT,
        RIGHT,
        LEFT_UP,
        LEFT_DOWN,
        RIGHT_UP,
        RIGHT_DOWN
    };
    Direction direction;
    EnemyBullet bullet;
    std::vector<EnemyBullet> bullets;
    int random_direction;
    void randomize_direction();
    bool is_in_map_area();
    bool can_move_up();
    bool can_move_down();
    bool can_move_left();
    bool can_move_right();

  public:
    Enemy(int &x, int &y, const char &symbol);
    void switch_direction();
    void Move() override;
    void fire() override;
    int &get_move_timer();
    void set_move_timer(int move_timer);
    EnemyBullet &get_bullet();
    std::vector<EnemyBullet> &get_bullets();
};

#endif