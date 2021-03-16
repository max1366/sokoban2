/*
** EPITECH PROJECT, 2021
** display_map
** File description:
** my_sokoban
*/

#include "../include/my_sokoban.h"

void replace_o(char **map, int i, int j, char **map_copy)
{
    if (map[i][j] == ' ' && map_copy[i][j] == 'O')
        map[i][j] = 'O';
}

void check_o_positions(char **map, coord_t size, char **map_copy)
{
    for (int i = 0; i < size.height; i++) {
        for (int j = 0; map[i][j] != '\n'; j++)
            replace_o(map, i, j, map_copy);
    }
}

void display_map(char **map, coord_t size, char **map_copy)
{
    int i = 0;

    check_o_positions(map, size, map_copy);
    if (COLS + 1 < size.width || LINES < size.height) {
        mvprintw((LINES / 2), (COLS / 2) - 8, "Window too small");
        return;
    }
    while (i < size.height) {
        mvprintw(i, 0, map[i]);
        i++;
    }
}