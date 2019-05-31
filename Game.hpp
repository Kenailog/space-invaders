// #ifndef GAME_HPP
// #define GAME_HPP

// #include <string>
// #include "GameStateManager.hpp"
// #include "Screen.hpp"
// #include "Player.hpp"
// #include "PlayerBullet.hpp"
// #include "Enemy.hpp"
// #include "EnemyBullet.hpp"

// class Game
// {
// private:
//   short speed = 100;

//   const short SCREEN_WIDTH = 22;
//   const short SCREEN_HEIGHT = 22;
//   char wall_symbol = ' ';

//   const short PLAYER_START_POSITION_X = SCREEN_WIDTH * .5;
//   const short PLAYER_START_POSITION_Y = SCREEN_HEIGHT * .8;

//   const char PLAYER_SYMBOL = 'O';
//   const char PLAYER_BULLET_SYMBOL = '!';

//   int ENEMY_POSITION_X = rand() % (SCREEN_WIDTH - 1);
//   int ENEMY_POSITION_Y = 2;

//   const char ENEMY_SYMBOL = 'v';
//   const char ENEMY_BULLET_SYMBOL = '|';

//   const std::string GAME_AUTHOR = "GOLIANEK PRODUCTIONS";
//   const std::string GAME_TITLE = "GALACTIC INVADERS";
//   const std::string WIN = "YOU WIN!";
//   const std::string PRESS_ANY_KEY = "PRESS ANY KEY";

//   int player_score = 0;
//   short player_health = 10;
//   short player_bullet_timer = 5;
//   short enemy_health = 3;
//   short enemy_bullet_timer = 2;
//   short enemy_move_timer = 1;
//   short number_of_enemies = 4;

//   std::vector<Enemy> enemies;

//   Screen* screen = nullptr;
//   Player* player = nullptr;
//   Enemy* enemy = nullptr;

// public:
//   Game();
//   ~Game();
//   const std::string &get_game_author() const;
//   const std::string &get_game_title() const;
//   const std::string &get_win_information() const;
//   const std::string &get_press_any_key() const;
//   short get_speed() const;
//   void set_speed(short speed);
//   const short &get_screen_width() const;
//   const short &get_screen_height() const;
//   char get_wall_symbol() const;
//   void set_wall_symbol(char symbol);
//   const short &get_player_start_position_x() const;
//   const short &get_player_start_position_y() const;
//   const char &get_player_symbol() const;
//   const char &get_player_bullet_symbol() const;
//   int get_enemy_start_position_x() const;
//   int get_enemy_start_position_y() const;
//   const char &get_enemy_symbol() const;
//   const char &get_enemy_bullet_symbol() const;
//   short get_number_of_enemies() const;
//   void set_number_of_enemies(short number);
//   std::vector<Enemy> get_enemies();

//   void menu() const;
// };

// #endif