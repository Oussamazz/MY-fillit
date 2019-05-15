/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 15:09:45 by oelazzou          #+#    #+#             */
/*   Updated: 2019/05/15 02:40:57 by oelazzou         ###   ########.fr       */
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
char	**tetri_map_init(int size)
{
	int x;
	int y;
	char **map;

	if(!(map = ft_memalloc(sizeof(char*) * size + 1)))
		return (NULL);
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

	i = x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			if (tr->x[i] == x && tr->y[i] == y)
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

char	**remove_tetri(char **map, t_tetris *tr, int size, int posx, int posy)
{
	int x;
	int y;
	int i;

	i = 0;
	x = posx;
	y = posy;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			if (map[x][y] == tr->c)
			{
				map[x][y] = '.';
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

/* get (x, y) of every tags of a tetrimino */
t_tetris	*get_pos(char *arr, char c)
{
	int i;
	int j;
	t_tetris *tetris;

	tetris = (t_tetris*)ft_memalloc(sizeof(t_tetris));
	if (!tetris)
		return (NULL);
	i = 0;
	j = 0;
	tetris->c = c;
	while (arr[i] && j <= 3 && i <= 19)
	{
		if (arr[i] == '#')
		{
			tetris->x[j] = i / 5;
			tetris->y[j] = i % 5;
			j++;
		}
		i++;
	}
	return (tetris);
}

