/*
** EPITECH PROJECT, 2021
** find_pos_o
** File description:
** my_sokoban
*/

#include "../include/my_sokoban.h"

void verif_o_or_x(char c, int *nbr_x, int *nbr_o)
{
    if (c == 'O')
        *nbr_o += 1;
    else if (c == 'X')
        *nbr_x += 1;
}

int find_o_positions(char **map, coord_t size)
{
    int nbr_o = 0;
    int nbr_x = 0;

    for (int i = 0 ; i < size.height ; i++) {
        for (int j = 0 ; map[i][j] != '\n' ; j++)
            verif_o_or_x(map[i][j], &nbr_o, &nbr_x);
    }
    if (nbr_o != nbr_x) {
        my_putstr("Please enter a valid map\n");
        exit (84);
    }
    return (nbr_o);
}

void verif_x(char c, int *nbr_x)
{
    if (c == 'X')
        *nbr_x += 1;
}

int find_x(char **map, coord_t size)
{
    int nbr_x = 0;

    for (int i = 0 ; i < size.height ; i++) {
        for (int j = 0 ; map[i][j] != '\n' ; j++)
            verif_x(map[i][j], &nbr_x);
    }
    return (nbr_x);
}
