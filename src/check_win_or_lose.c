/*
** EPITECH PROJECT, 2021
** check_win_or_lose
** File description:
** my_sokoban
*/

#include "../include/my_sokoban.h"

int check_o_visible(char **map, int i, int j, char **map_copy)
{
    if (map[i][j] == 'X' && map_copy[i][j] == 'O') {
        return (1);
    } else if (map_copy[i][j] == 'O' && map[i][j] != 'X') {
        return (-1);
    }
    return (0);
}

void check_win(char **map, coord_t size, char **map_copy, int nbr_o)
{
    int a = 0;

    for (int i = 0 ; i < size.height ; i++) {
        for (int j = 0 ; map[i][j] != '\n' ; j++)
            a += check_o_visible(map, i, j, map_copy);
    }
    if (a == nbr_o) {
        refresh();
        clear();
        endwin();
        exit (0);
    }
}

int check_x_corner(char **map, int i, int j)
{
    if (map[i][j] == 'X' && ((map[i][j + 1] == '#' || map[i][j + 1] == 'X')
    || (map[i][j - 1] == '#' || map[i][j - 1] == 'X'))
    && ((map[i + 1][j] == '#' || map[i + 1][j] == 'X')
    || (map[i - 1][j] == '#' || map[i - 1][j] == 'X')))
        return (1);
    return (0);
}

void check_lose(char **map, coord_t size)
{
    int nbr_x = find_x(map, size);
    int a = 0;

    for (int i = 0 ; i < size.height ; i++) {
        for (int j = 0 ; map[i][j] != '\n' ; j++)
            a += check_x_corner(map, i, j);
    }
    if (a == nbr_x) {
        refresh();
        clear();
        endwin();
        exit (1);
    }
}

void check_win_or_lose(char **map, coord_t size, char **map_copy, int nbr_o)
{
    check_win(map, size, map_copy, nbr_o);
    check_lose(map, size);
}