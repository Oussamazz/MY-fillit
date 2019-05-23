/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 15:09:45 by oelazzou          #+#    #+#             */
/*   Updated: 2019/05/23 21:54:10 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int n)
{
	int	i;

	i = 1;
	while (i <= n / 2)
	{
		if (i * i >= n)
			return (i);
		i++;
	}
	return (-1);
}

char	**tetri_map_init(char **map, int size)
{
	int	x;
	int	y;

	if (!(map = ft_memalloc(sizeof(char*) * size + 1)))
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

char	**insert_tetri(char **map, t_tetris *tr, int size, int pos_y, int pos_x)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (pos_y < size)
	{
		while (pos_x < size)
		{
			if (tr->y[i] == pos_y && tr->x[i] == pos_x
				&& map[pos_y][pos_x] == '.')
			{
				map[pos_y][pos_x] = tr->c;
				i++;
				count++;
			}
			if (count == 4)
				return (map);
			pos_x++;
		}
		pos_y++;
		pos_x = 0;
	}
	return (map);
}

char	**remove_tetri(char **map, t_tetris *tr, int size, int pos_y, int pos_x)
{
	int	x;
	int	y;
	int	count;

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

void	get_pos(t_tetris **tr, char *arr, char c)
{
	int	i;
	int	j;

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
