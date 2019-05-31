#include <string>

#include "GameStateManager.hpp"
#include "Screen.hpp"
#include "Player.hpp"
#include "PlayerBullet.hpp"
#include "Enemy.hpp"
#include "EnemyBullet.hpp"

int main()
{
    srand(time((unsigned int) 0));

    const short GAME_SPEED = 100;

    const short SCREEN_WIDTH = 50;
    const short SCREEN_HEIGHT = 50;
    char wall_symbol = ' ';
    char wall_symbol_in_menu = '#';

    const short PLAYER_START_POSITION_X = SCREEN_WIDTH * .5;
    const short PLAYER_START_POSITION_Y = SCREEN_HEIGHT * .8;

    const char PLAYER_SYMBOL = '~';
    const char PLAYER_BULLET_SYMBOL = '!';

    int ENEMY_POSITION_X = rand() % (SCREEN_WIDTH - 1);
    int ENEMY_POSITION_Y = 2;

    const char ENEMY_SYMBOL = 'x';
    const char ENEMY_BULLET_SYMBOL = '|';

    const std::string GAME_AUTHOR = "GOLIANEK PRODUCTIONS";
    const std::string PRESENTS = "presents";
    const std::string GAME_TITLE = "GALACTIC INVADERS";
    const std::string NEW_GAME = "1. NEW GAME";
    const std::string EXIT = "2. EXIT";
    struct KeyBindings
    {
        const std::string LEFT = "A -> move left";
        const std::string RIGHT = "D -> move right";
        const std::string SHOOT = "W -> shoot";
        const std::string STOP = "S -> stop";
    };
    const std::string WIN = "YOU WIN!";
    const std::string PRESS_ANY_KEY = "PRESS ANY KEY";

    int player_score = 0;
    short player_health = 10;
    short player_bullet_timer = 5;
    short enemy_health = 3;
    short enemy_bullet_timer = 2;
    short enemy_move_timer = 4;
    short number_of_enemies = 10;

    KeyBindings bindings;
    KeyBindings* key_bindings = &bindings;

    Screen* screen = new Screen(SCREEN_WIDTH, SCREEN_HEIGHT, wall_symbol);
    Player* player = new Player(PLAYER_START_POSITION_X, PLAYER_START_POSITION_Y, PLAYER_SYMBOL);
    Enemy* enemy = new Enemy(ENEMY_POSITION_X, ENEMY_POSITION_Y, ENEMY_SYMBOL);

    player->set_health(player_health);
    player->set_score(player_score);
    player->get_bullet().set_symbol(PLAYER_BULLET_SYMBOL);
    player->set_bullet_timer(player_bullet_timer);

    enemy->set_health(enemy_health);
    enemy->set_bullet_timer(enemy_bullet_timer);
    enemy->set_move_timer(enemy_move_timer);
    enemy->get_bullet().set_symbol(ENEMY_BULLET_SYMBOL);

    std::vector<Enemy> enemies;

    for (size_t i = 0; i < number_of_enemies; i++)
    {
        enemies.push_back(*enemy);
    }

    // std::vector<GameObject*>* game_objects = &GameObject::game_objects;
    // PlayerBullet* ptr_player_bullet = &player->player_bullet;

    /**********************************************************************/

    screen->set_cursor(0, 0);
    screen->clear_console();
    screen->draw_map_walls();
    screen->clear_map();

    Sleep(1000);

    screen->draw_in_the_middle_of_width(GAME_AUTHOR, .5);

    screen->display();
    Sleep(3000);
    screen->clear_console();

    screen->draw_in_the_middle_of_width(PRESENTS, .6);

    screen->display();
    Sleep(2000);
    screen->clear_map();
    screen->clear_console();

    screen->draw_in_the_middle_of_width(GAME_TITLE, .5);

    screen->display();
    Sleep(4000);
    screen->clear_map();
    screen->clear_console();
    screen->display();
    Sleep(500);
    screen->clear_console();

    while (!_kbhit())
    {
        screen->draw_in_the_middle_of_width(PRESS_ANY_KEY, .5f);
        screen->display();
        Sleep(600);
        screen->clear_console();
        Sleep(600);
    }

    for (float i = 5; i > 1; i -= .1f)
    {
        screen->draw_in_the_middle_of_width(GAME_TITLE, i * .1f);
        screen->display();
        Sleep(10);
        screen->clear_console();
        screen->clear_map();
    }

    screen->set_wall_symbol(wall_symbol_in_menu);
    screen->draw_map_walls();
    screen->draw_in_the_middle_of_width(GAME_TITLE, .1f);
    screen->draw_in_the_middle_of_width(NEW_GAME, .45f);
    screen->draw_in_the_middle_of_width(EXIT, .55f);
    screen->display();

    while (true)
    {
        if (_getch() == '1')
        {
            screen->clear_console();
            screen->clear_map();
            screen->draw_in_the_middle_of_width(key_bindings->LEFT, .4f);
            screen->draw_in_the_middle_of_width(key_bindings->RIGHT, .45f);
            screen->draw_in_the_middle_of_width(key_bindings->SHOOT, .55f);
            screen->draw_in_the_middle_of_width(key_bindings->STOP, .6f);
            screen->display();
            _getch();
            screen->clear_console();
            screen->set_wall_symbol(wall_symbol);
            screen->draw_map_walls();
            break;
        }
        else if (_getch() == '2')
        {
            screen->set_cursor(1, 10);
            screen->clear_console();
            delete player;
            delete enemy;
            delete screen;
            exit(0);
        }
        else
        {
            continue;
        }
    }

    while (!GameStateManager::isOver)
    {
        screen->clear_map();
        player->input();

        /* Draw */
        screen->draw(player);

		for (auto enemy : enemies)
		{
			screen->draw(&enemy);
		}

        for (auto player_bullet : player->get_bullets())
        {
            screen->draw(&player_bullet);
        }

        for (auto enemy : enemies)
        {
            for (auto bullet : enemy.get_bullets())
            {
                screen->draw(&bullet);
            }
        }

        /* Move */
        if (player->get_x() > 1 && player->get_x() < screen->get_width() - 2)
        {
            player->Move();
        }

        if (player->get_x() == 1)
        {
            player->set_x(2);
        }
        else if (player->get_x() == screen->get_width() - 2)
        {
            player->set_x(screen->get_width() - 3);
        }

        for (size_t i = 0; i < enemies.size(); i++)
        {
            if (enemies[i].get_move_timer() > 0)
            {
                enemies[i].set_move_timer(enemies[i].get_move_timer() - 1);
            }
        }

        for (size_t i = 0; i < enemies.size(); i++)
        {
            if (enemies[i].get_move_timer() == 0)
            {
                enemies[i].switch_direction();
                enemies[i].set_move_timer(rand() % 4/*enemy_move_timer*/);
            }
        }

        for(size_t i = 0; i < enemies.size(); i++)
        {
            enemies[i].Move();
        }
        
        if (player->get_bullet_timer() > 0)
        {
            player->set_bullet_timer(player->get_bullet_timer() - 1);
        }

        for (size_t i = 0; i < enemies.size(); i++)
        {
            if (enemies[i].get_bullet_timer() > 0)
            {
                enemies[i].set_bullet_timer(enemies[i].get_bullet_timer() - 1);
            }
        }

        for (size_t i = 0; i < enemies.size(); i++)
        {
            if (enemies[i].get_x() == player->get_x() && enemies[i].get_bullet_timer() == 0)
            {
                enemies[i].fire();
                enemies[i].set_bullet_timer(enemy_bullet_timer);
            }
        }

        for (size_t i = 0; i < enemies.size(); i++)
        {
            for (size_t j = 0; j < enemies[i].get_bullets().size(); j++)
            {
                enemies[i].get_bullets()[j].Move();
            }
        }

        for (size_t i = 0; i < player->get_bullets().size(); i++)
        {
            player->get_bullets()[i].Move();
        }

        /* Erase */
        for (size_t i = 0; i < player->get_bullets().size(); i++)
        {
            if (player->get_bullets()[i].get_y() <= 0)
            {
                player->get_bullets().erase(player->get_bullets().begin() + i);
            }
        }

        for (size_t i = 0; i < enemies.size(); i++)
        {
            for (size_t j = 0; j < player->get_bullets().size(); j++)
            {
                if (player->get_bullets()[j].get_y() == enemies[i].get_y() && player->get_bullets()[j].get_x() == enemies[i].get_x())
                {
                    player->set_score(player->get_score() + 10);
                    player->get_bullets().erase(player->get_bullets().begin() + j);
                    enemies[i].set_health(enemies[i].get_health() - 1);
                }
            }
        }

        for (size_t i = 0; i < enemies.size(); i++)
        {
            for (size_t j = 0; j < enemies[i].get_bullets().size(); j++)
            {
                if (enemies[i].get_bullets()[j].get_y() >= screen->get_width())
                {
                    enemies[i].get_bullets().erase(enemies[i].get_bullets().begin() + j);
                }
            }
        }

        for (size_t i = 0; i < enemies.size(); i++)
        {
            for (size_t j = 0; j < enemies[i].get_bullets().size(); j++)
            {
                if (enemies[i].get_bullets()[j].get_y() == player->get_y() && enemies[i].get_bullets()[j].get_x() == player->get_x())
                {

                    enemies[i].get_bullets().erase(enemies[i].get_bullets().begin() + j);
                    player->set_health(player->get_health() - 1);
                }
            }
        }

        if (player->get_health() == 0)
        {
            GameStateManager::isOver = true;
        }

        for (size_t i = 0; i < enemies.size(); i++)
        {
            if (enemies[i].get_health() == 0)
            {
                enemies.erase(enemies.begin() + i);
                number_of_enemies--;
            }
        }

        if (number_of_enemies == 0)
        {
            screen->clear_map();
            screen->draw_in_the_middle_of_width(WIN, .5);
            screen->display();
            if (_getch() == 'x')
            {
                GameStateManager::isOver = true;
            }
        }

        screen->display();
		std::cout << "\nLIVES " << player->get_health() << "\tSCORE " << player->get_score() << std::endl;
        screen->clear_console();
        Sleep(100 - GAME_SPEED);
    }

    screen->set_cursor(1, 10);

    delete player;
    delete enemy;
    delete screen;
}