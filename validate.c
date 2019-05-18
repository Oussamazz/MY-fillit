/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:00:36 by oelazzou          #+#    #+#             */
/*   Updated: 2019/05/15 01:39:40 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		check_tetri_count(int tetri_count)
{
	if (!(1 <= tetri_count || tetri_count <= 26))
		exit_error();
}

void		check_tags_count(char *arr)
{
	int newlines;
	int tags;
	int dots;

	dots = 0;
	tags = 0;
	newlines = 0;
	if (arr == NULL)
		exit_error();
	while(*arr)
	{
		if (*arr == '#')
			tags++;
		if (*arr == '\n')
			newlines++;
		else if(*arr == '.')
			dots++;
		arr++;
	}
	if (tags != 4 || newlines != 4 || dots != 12)
		exit_error();
}

void		check_tags_pos(char *arr)
{
	int j;
	int touch;

	j = 0;
	touch = 0;
	if (arr)
	{
		while (arr[j])
		{
			if(arr[j] == '#')
			{
				if (arr[j + 1] == '#')
					touch++;
				if (arr[j - 1] == '#')
					touch++;
				if (arr[j - 5] == '#')
					touch++;
				if (arr[j + 5] == '#')
					touch++;
			}
			j++;
		}
		if (!(touch == 6 || touch == 8))
		{
			ft_putnbr(touch);
			exit_error();
		}
		return ;
	}
	exit_error();
}

int	check_tetri(char **map, t_tetris *tr, int size)
{
	int x;
	int y;
	int i;

	x = i = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			if (tr->x[i] < size && tr->y[i] < size && map[tr->x[i]][tr->y[i]] == '.')
			{
				i++;
				if (i == 4)
					return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

void		check_all(char *arr)
{
	int i;
	int size;
	int add21;
	char *tmp;

	tmp = NULL;
	check_tetri_count(count_tetri(arr));
	add21 = 0;
	while (arr[add21] != '\0')
	{
		tmp = ft_strsub(arr, add21, 20);
		check_tags_count(tmp);
		check_tags_pos(tmp);
		ft_strdel(&tmp);
		add21 += 21;
	}
}
