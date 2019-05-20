/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 00:05:37 by oelazzou          #+#    #+#             */
/*   Updated: 2019/05/20 21:44:36 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	    xy_tetri(t_tetris **tetri, int x, int y)
{
	int	pos_x;
	int pos_y;
	int i;

	i = 0;
	pos_x = 100;
	pos_y = 100;
	while (i < 4)
	{
		if ((*tetri)->x[i] < pos_x)
			pos_x = (*tetri)->x[i];
		if ((*tetri)->y[i] < pos_y)
			pos_y = (*tetri)->y[i];
		i++;
	}
	i--;
	while (i >= 0)
	{
		(*tetri)->x[i] = (*tetri)->x[i] - pos_x + x;
		(*tetri)->y[i] = (*tetri)->y[i] - pos_y + y;
		i--;
	}
}
/* get all positions of tetriminos */

t_tetris	*get_all_tetri(char *line)
{
	t_tetris *tr;
	char letter;
	int add21;
	int tetri_count;
	t_tetris *tmp;

	tetri_count = count_tetri(line);
	add21 = 0;
	letter = 'A';
	if(!(tr = (t_tetris*)ft_memalloc(sizeof(t_tetris))))
			return (NULL);
	tmp = tr;
	while (tetri_count > 0)
	{
		get_pos(&tmp, ft_strsub(line, add21, 20) , letter);
		letter++;
		add21 += 21;
		tetri_count--;
		if (!(tmp->next = (t_tetris*)ft_memalloc(sizeof(t_tetris))))
			return (NULL);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	return (tr);
}


char	**solver(char **map, t_tetris *tr, int size)
{
	int x;
	int y;
	char **result;
	if (tr->next == NULL)
		return (map);
	y = 0;
	result = NULL;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			xy_tetri(&tr, x, y);
			if (check_tetri(map, tr, size))
				result = solver((insert_tetri(map, tr, size, y, x)), tr->next, size);
			if (result)
				return (result);
			map = remove_tetri(map, tr, size, y, x);
			x++;
		}
		y++;
	}
	return (NULL);
}


void	solve(int size, t_tetris *tr)
{
	char **map;
	char **result;
	
	map = NULL;
	map = tetri_map_init(map, size);
	result = NULL;
	while (!(result = solver(map, tr, size)))
	{
		size++;
		ft_strdel(map);
		map = tetri_map_init(map, size);
	}
	print_map(result);
	return ;
}

void	print_map(char **map)
{
	int i;
	
	if (map == NULL)
		exit_error();
	i = 0;
	while (map[i])
	{
		ft_putendl(map[i]);
		i++;
	}
}
