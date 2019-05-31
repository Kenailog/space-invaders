#ifndef Screen_H
#define Screen_H

#include <iostream>
#include <windows.h>

#include "GameObject.hpp"

class Screen
{
  private:
    static const int width;
    static const int height;
    char map_matrix[50][50];
    // std::vector<std::vector<char>> map;
    // std::vector<char> col;
    char wall_symbol;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

  public:
    Screen();
    Screen(const int &width, const int &height, char &wall_symbol);
    static int get_width();
    static int get_height();
    void draw_map_walls();
    void draw(GameObject *game_object);
    void draw_on_position(char symbol, int x, int y);
    void draw_in_range(std::string string, int x, int y);
    void draw_in_the_middle_of_width(std::string string, float y);
    void display() const;
    void clear_console() const;
    void clear_map();
    void clear_map_on_position(int x, int y);
    // void clear_map_in_range(int x_1, int y_1, int x_2, int y_2);
    void set_cursor(bool visible, DWORD size) const;
    void set_wall_symbol(char symbol);
    HANDLE &get_console();
};

#endif