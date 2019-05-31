#include "Screen.hpp"

Screen::Screen(){};

Screen::Screen(const int &width, const int &height, char &wall_symbol)
{
    this->wall_symbol = wall_symbol;
    // this->col.resize(width);
    // this->map.resize(height);
    // this->map_matrix[width][height];
}

const int Screen::width = 50;
const int Screen::height = 50;

int Screen::get_width()
{
    return width;
}

int Screen::get_height()
{
    return height;
}

void Screen::draw_map_walls()
{
    for (int i = 0; i < this->width; i++)
    {
        this->map_matrix[0][i] = this->wall_symbol;
        this->map_matrix[this->width - 1][i] = this->wall_symbol;
    }

    for (int i = 0; i < this->height; i++)
    {
        this->map_matrix[i][0] = this->wall_symbol;
        this->map_matrix[i][this->height - 1] = this->wall_symbol;
    }
}

void Screen::draw(GameObject *game_object)
{
    for (int i = 1; i < this->height - 1; i++)
    {
        for (int j = 1; j < this->width - 1; j++)
        {
            if (game_object->get_y() == i && game_object->get_x() == j)
            {
                this->map_matrix[i][j] = game_object->get_symbol();
            }
        }
    }
}

void Screen::draw_on_position(char symbol, int x, int y)
{
    this->map_matrix[y][x] = symbol;
}

void Screen::draw_in_range(std::string string, int x, int y)
{
    for (int i = 0; i < string.size(); i++)
    {
        this->draw_on_position(string[i], x + i, y);
    }
}

void Screen::draw_in_the_middle_of_width(std::string string, float y)
{
    for (int i = 0; i < string.size(); i++)
    {
        this->draw_on_position(string[i], (int)((this->width - string.size()) * .5) + i, (int)(this->height * y));
    }
}

void Screen::display() const
{
    for (int i = 0; i < this->width; i++)
    {
        std::cout << this->map_matrix[0][i];
    }
    std::cout << std::endl;

    for (int i = 1; i < this->height - 1; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            std::cout << this->map_matrix[i][j];
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < this->width; i++)
    {
        std::cout << this->map_matrix[this->height - 1][i];
    }
}

void Screen::clear_console() const
{
    COORD cur = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
    // system("cls");
}

void Screen::clear_map()
{
    for (int i = 1; i < this->height - 1; i++)
    {
        for (int j = 1; j < this->width - 1; j++)
        {
            if (this->map_matrix[i][j] != ' ')
            {
                this->map_matrix[i][j] = ' ';
            }
        }
    }
}

void Screen::clear_map_on_position(int x, int y)
{
    this->map_matrix[y][x] = ' ';
}

// void Screen::clear_map_in_range(int x, int y)
// {
//     for(size_t i = 0; i < ; i++)
//     {
//         this->clear_map_on_position(x + i, y);
//     }
// }

void Screen::set_cursor(bool visible, DWORD size) const
{
    if (size == 0)
    {
        size = 20;
    }

    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}

void Screen::set_wall_symbol(char symbol)
{
    this->wall_symbol = symbol;
}

HANDLE &Screen::get_console()
{
    return this->console;
}