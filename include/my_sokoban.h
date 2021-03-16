/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** my_sokoban
*/

#ifndef my_sokoban
#define my_sokoban

#include <ncurses.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
typedef struct coord
{
    int width;
    int height;
} coord_t;

int my_putstr(char const *str);
void my_putchar(char c);
void verif_p(char **map, coord_t pos_char, coord_t *pos, int *a);
coord_t find_pos_player(char **map, coord_t size);
void scan_keyboard(char **map, coord_t size, int key);
void gest_error(int size, char **str);
void my_loop(char **map, coord_t size);
char *load_file_in_mem(char const *filepath);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
coord_t find_size_of_map(char *str);
char **mem_dup_2d_array(char **arr, int nb_rows, int nb_cols);
char **load_2d_arr_from_file(char const *filepath);
void verif_o_or_x(char c, int *nbr_x, int *nbr_o);
int find_o_positions(char **map, coord_t size);
void verif_x(char c, int *nbr_x);
int find_x(char **map, coord_t size);
void replace_o(char **map, int i, int j, char **map_copy);
void check_o_positions(char **map, coord_t size, char **map_copy);
void display_map(char **map, coord_t size, char **map_copy);
void up_arrow(char **map, coord_t pos_player);
void down_arrow(char **map, coord_t pos_player);
void left_arrow(char **map, coord_t pos_player);
void right_arrow(char **map, coord_t pos_player);
int check_o_visible(char **map, int i, int j, char **map_copy);
void check_win(char **map, coord_t size, char **map_copy, int nbr_o);
int check_x_corner(char **map, int i, int j);
void check_lose(char **map, coord_t size);
void check_win_or_lose(char **map, coord_t size, char **map_copy, int nbr_o);


#endif /* !my_sokoban */