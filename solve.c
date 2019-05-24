/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 00:05:37 by oelazzou          #+#    #+#             */
/*   Updated: 2019/05/24 22:32:44 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		adjust_tetri(t_tetris **tr, int y, int x)
{
	int		pos_x;
	int		pos_y;
	int		i;

	i = 0;
	pos_x = 69;
	pos_y = 69;
	while (i < 4)
	{
		if (pos_x > (*tr)->x[i])
			pos_x = (*tr)->x[i];
		if (pos_y > (*tr)->y[i])
			pos_y = (*tr)->y[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		(*tr)->x[i] = (*tr)->x[i] - pos_x + x;
		(*tr)->y[i] = (*tr)->y[i] - pos_y + y;
		i++;
	}
}

t_tetris	*get_all_tetri(char *line)
{
	int			add21;
	int			tetri_count;
	char		letter;
	t_tetris	*tr;
	t_tetris	*tmp;

	tmp = NULL;
	tetri_count = count_tetri(line);
	add21 = 0;
	letter = 'A';
	if (!(tr = (t_tetris*)ft_memalloc(sizeof(t_tetris))))
		return (NULL);
	tmp = tr;
	while (tetri_count > 0)
	{
		get_pos(&tmp, ft_strsub(line, add21, 20), letter);
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

char		**solver(char **map, t_tetris *tr, int size)
{
	int		x;
	int		y;
	int		flag;
	char	**result;

	if (tr->next == NULL)
		return (map);
	y = 0;
	result = NULL;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			tr->pos_y = y;
			tr->pos_x = x;
			flag = 0;
			adjust_tetri(&tr, y, x);
			if ((flag = check_tetri(map, tr, size)))
				result = solver((insert_tetri(map, tr, size)), tr->next, size);
			if (result)
				return (result);
			if (flag)
				map = remove_tetri(map, tr, size);
			x++;		
		}
		y++;
	}
	return (NULL);
}

void		solve(int size, t_tetris *tr)
{
	char	**map;
	char	**result;

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
