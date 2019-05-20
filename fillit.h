/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:12:01 by oelazzou          #+#    #+#             */
/*   Updated: 2019/05/20 21:08:52 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H

#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int		ft_sqrt(int n);
char	*read_file(int fd);
void	is_invalid_char(char c);
int		count_tetri(char *arr);
void	check_tetri_count(int tetri_count);
void	check_tags_pos(char *arr);
void	check_tags_count(char *arr);
void	check_all(char *arr);
void	exit_error(void);
typedef struct s_tetris
{
    char    c;
    int     x[4];
    int     y[4];
    struct s_tetris *next;
}              t_tetris;
void		get_pos(t_tetris **tr, char *arr, char c);
t_tetris	*get_all_tetri(char *line);
void	    xy_tetri(t_tetris **tetri, int x, int y);
int			check_tetri(char **map, t_tetris *tr, int size);
char	**tetri_map_init(char **map, int size);
char	**insert_tetri(char **map, t_tetris *tr, int size, int y, int x);
char	**remove_tetri(char **map, t_tetris *tr, int size, int y, int x);
char	**solver(char **map, t_tetris *tr, int size);
void	solve(int size, t_tetris *tr);
void	print_map(char **map);
#endif
