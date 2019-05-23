/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:50:55 by oelazzou          #+#    #+#             */
/*   Updated: 2019/05/23 21:56:06 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	is_invalid_char(char c)
{
	if (!(c == '.' || c == '#' || c == '\n'))
		exit_error();
}

int		count_tetri(char *arr)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (arr)
	{
		while (arr[i] != '\0')
		{
			if (arr[i] == '#')
				count++;
			i++;
		}
		return (count / 4);
	}
	return (-1);
}

char	*read_file(int fd)
{
	int		i;
	int		j;
	char	c;
	char	*tmp;

	j = 0;
	if (!(tmp = ft_strnew(547)) || fd < 0)
		exit_error();
	i = read(fd, &c, 1);
	if (i == 1)
	{
		while (i == 1)
		{
			tmp[j] = c;
			is_invalid_char(tmp[j]);
			i = read(fd, &c, 1);
			j++;
		}
		return (tmp);
	}
	exit_error();
	return (NULL);
}
