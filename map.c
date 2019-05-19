/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 15:09:45 by oelazzou          #+#    #+#             */
/*   Updated: 2019/05/15 20:45:04 by oelazzou         ###   ########.fr       */
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
char	**insert_tetri(char **map, t_tetris *tr, int size)
{
	int x;
	int y;
	int i;

	i = 0;
	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			if (tr->x[i] == y && tr->y[i] == x)
			{
				map[x][y] = tr->c;
				i++;
				if (i == 4)
					return (map);
			}
			y++;
		}
		x++;
	}
	return (map);
}

/* removing a tetrimino */

char	**remove_tetri(char **map, t_tetris *tr, int size)
{
	int x;
	int y;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			if (map[x][y] == tr->c)
				map[x][y] = '.';
			y++;
		}
		x++;
	}
	return (map);
}

/* get (x, y) of every tags of a tetrimino */
void		get_pos(t_tetris **tr, char *arr, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	(*tr)->c = c;
	while (arr[i] && j <= 3)
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

