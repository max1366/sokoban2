/*
** EPITECH PROJECT, 2021
** load_file_in_mem
** File description:
** my_sokoban
*/

#include "../include/my_sokoban.h"

char *load_file_in_mem(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buf = malloc(sizeof(char) * 100010006);
    int size = read(fd, buf, 100010006);

    buf[size] = 0;
    close(fd);
    return (buf);
}

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **array = malloc(sizeof(char *) * nb_rows);

    for (int i = 0 ; i < nb_rows ; i++)
        array[i] = malloc(sizeof(char) * nb_cols);
    return (array);
}

coord_t find_size_of_map(char *str)
{
    coord_t size = {0, 0};
    char *map = load_file_in_mem(str);
    int j = 0;

    for (int i = 0 ; map[i] != 0 ; i++) {
        j += 1;
        if (j > size.width)
            size.width = j;
        if (map[i] == '\n' || map[i + 1] == '\0') {
            size.height += 1;
            j = 0;
        }
    }
    free (map);
    return (size);
}

char **mem_dup_2d_array(char **arr, int nb_rows, int nb_cols)
{
    char **new_arr = malloc(sizeof(char *) * nb_rows);
    int i = 0;
    int j = 0;

    for (int i = 0 ; i < nb_rows ; i++)
        new_arr[i] = malloc(sizeof(char) * nb_cols);
    while (i < nb_rows) {
        while (j < nb_cols) {
            new_arr[i][j] = arr[i][j];
            j += 1;
        }
        j = 0;
        i += 1;
    }
    return (new_arr);
}

char **load_2d_arr_from_file(char const *filepath)
{
    char **str;
    char *buf = load_file_in_mem(filepath);
    int i = 0;
    int j = 0;
    int n = 0;
    coord_t size = find_size_of_map((char *)filepath);

    str = mem_alloc_2d_array(size.height, size.width);
    while (i < size.height) {
        while (buf[n] != '\n' && buf[n] != 0) {
            str[i][j] = buf[n];
            j += 1;
            n += 1;
        }
        str[i][j] = '\n';
        n += 1;
        j = 0;
        i += 1;
    }
    return (str);
}