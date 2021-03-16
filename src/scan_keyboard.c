/*
** EPITECH PROJECT, 2021
** keyboard
** File description:
** my_sokoban
*/

#include "../include/my_sokoban.h"

void verif_p(char **map, coord_t pos_char, coord_t *pos, int *a)
{
    if (map[pos_char.height][pos_char.width] == 'P') {
        pos->height = pos_char.height;
        pos->width = pos_char.width;
        *a += 1;
    }
}

coord_t find_pos_player(char **map, coord_t size)
{
    coord_t pos_p;
    coord_t pos_char;
    int a = 0;

    for (int i = 0 ; i < size.height ; i++) {
        for (int j = 0 ; j < size.width ; j++) {
            pos_char.height = i;
            pos_char.width = j;
            verif_p(map, pos_char, &pos_p, &a);
        }
    }
    if (a != 1) {
        endwin();
        my_putstr("Please enter a valid map\n");
        exit (84);
    }
    return (pos_p);
}

void scan_keyboard(char **map, coord_t size, int key)
{
    coord_t pos_player = find_pos_player(map, size);

    switch (key) {
    case 65:
        up_arrow(map, pos_player);
        break;
    case 66:
        down_arrow(map, pos_player);
        break;
    case 68:
        left_arrow(map, pos_player);
        break;
    case 67:
        right_arrow(map, pos_player);
        break;
    default:
        return;
    }
}