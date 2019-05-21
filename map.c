/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 15:09:45 by oelazzou          #+#    #+#             */
/*   Updated: 2019/05/21 20:25:48 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int n)
{
	int i;

	i = 1;
	while (i <= n / 2)
	{
		if (i * i >= n)
			return (i);
		i++;
	}
	return (-1);
}
 
 /* final_map */
char	**tetri_map_init(char **map, int size)
{
	int x;
	int y;

	if(!(map = ft_memalloc(sizeof(char*) * size + 1)))
		return (NULL);
	x = 0;
	while (x < size)
	{
		if (!(map[x] = ft_memalloc(sizeof(char) * size + 1)))
			return (NULL);
		y = 0;
		while (y < size)
		{
			map[x][y] = '.';
			y++;
		}
		map[x][y] = '\0';
		x++;
	}
	map[x] = NULL;
	return (map);
}

/* insert a tetrimino */
char	**insert_tetri(char **map, t_tetris *tr, int size, int pos_y, int pos_x)
{
	int i;
	int x;
	int y;
	int count;

	count = 0;
	i = 0;
	y = pos_y;
	x = pos_x;
	while (y < size)
	{
		while (x < size)
		{
			if (tr->y[i] == y && tr->x[i] == x && map[y][x] == '.')
			{
				map[y][x] = tr->c;
				i++;
				count++;
			}
			if (count == 4)
				return (map);
			x++;
		}
		y++;
		x = 0;
	}
	return (map);
}

/* removing a tetrimino */

char	**remove_tetri(char **map, t_tetris *tr, int size, int pos_y, int pos_x)
{
	int x;
	int y;
	int count;

	count = 0;
	y = pos_y;
	x = pos_x;
	while (y < size)
	{
		while (x < size)
		{
			if (map[y][x] == tr->c)
			{
				map[y][x] = '.';
				count++;
			}
			if (count == 4)
				return (map);
			x++;
		}
		y++;
		x = 0;
	}
	return (map);
}

/* get (x, y) of every tags of a tetrimino */
void		get_pos(t_tetris **tr, char *arr, char c)
{
	int i;
	int j;
	int pos_x;
	int pos_y;

	i = 0;
	j = 0;
	(*tr)->c = c;
	while (arr[i] != '\0')
	{
		if (arr[i] == '#')
		{
			(*tr)->x[j] = i % 5;
			(*tr)->y[j] = i / 5;
			j++;
		}
		i++;
	}
}
