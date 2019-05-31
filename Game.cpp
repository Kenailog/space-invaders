// #include "Game.hpp"

// Game::Game()
// {
//     this->screen = new Screen(SCREEN_WIDTH, SCREEN_HEIGHT, wall_symbol);
//     this->player = new Player(PLAYER_START_POSITION_X, PLAYER_START_POSITION_Y, PLAYER_SYMBOL);
//     this->enemy = new Enemy(ENEMY_POSITION_X, ENEMY_POSITION_Y, ENEMY_SYMBOL);    
// }

// Game::~Game()
// {
//     delete enemy;
//     delete player;
//     delete screen;
// }

// const std::string &Game::get_game_author() const
// {
//     return this->GAME_AUTHOR;
// }

// const std::string &Game::get_game_title() const
// {
//     return this->GAME_TITLE;
// }

// const std::string &Game::get_win_information() const
// {
//     return this->WIN;
// }

// const std::string &Game::get_press_any_key() const
// {
//     return this->PRESS_ANY_KEY;
// }

// short Game::get_speed() const
// {
//     return this->speed;
// }

// void Game::set_speed(short speed)
// {
//     this->speed = speed;
// }

// const short &Game::get_screen_width() const
// {
//     return this->SCREEN_WIDTH;
// }

// const short &Game::get_screen_height() const
// {
//     return this->SCREEN_HEIGHT;
// }

// char Game::get_wall_symbol() const
// {
//     return this->wall_symbol;
// }

// void Game::set_wall_symbol(char symbol)
// {
//     this->wall_symbol = wall_symbol;
// }

// const short &Game::get_player_start_position_x() const
// {
//     return this->PLAYER_START_POSITION_X;
// }

// const short &Game::get_player_start_position_y() const
// {
//     return this->PLAYER_START_POSITION_Y;
// }

// const char &Game::get_player_symbol() const
// {
//     return this->PLAYER_SYMBOL;
// }

// const char &Game::get_player_bullet_symbol() const
// {
//     return this->PLAYER_BULLET_SYMBOL;
// }

// int Game::get_enemy_start_position_x() const
// {
//     return this->ENEMY_POSITION_X;
// }

// int Game::get_enemy_start_position_y() const
// {
//     return this->ENEMY_POSITION_Y;
// }

// const char &Game::get_enemy_symbol() const
// {
//     return this->ENEMY_SYMBOL;
// }

// const char &Game::get_enemy_bullet_symbol() const
// {
//     return this->ENEMY_BULLET_SYMBOL;
// }

// short Game::get_number_of_enemies() const
// {
//     return this->number_of_enemies;
// }

// void Game::set_number_of_enemies(short number)
// {
//     this->number_of_enemies = number;
// }

// std::vector<Enemy> Game::get_enemies()
// {
//     return this->enemies;
// }

// void Game::menu() const
// {
//     for (size_t i = 5; i > 1; i -= .1)
//     {
//         screen->draw_in_the_middle_of_width(GAME_TITLE, i * .1);
//         screen->display();
//         Sleep(150);
//         screen->clear_console();
//         screen->clear_map();
//     }

//     screen->set_wall_symbol(wall_symbol_in_menu);
//     screen->draw_map_walls();
//     screen->draw_in_the_middle_of_width(GAME_TITLE, .1);
//     screen->draw_in_the_middle_of_width(NEW_GAME, .45);
//     screen->draw_in_the_middle_of_width(EXIT, .55);
//     screen->display();
// }