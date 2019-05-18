/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:59:40 by oelazzou          #+#    #+#             */
/*   Updated: 2019/05/15 20:51:23 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     main(int ac, char **av)
{
	char *line;
	int fd;
	t_tetris *tr;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit file\n");
		exit_error();
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit_error();
	line = read_file(fd);
	check_all(line);
	ft_putnbr(1);
	return (0);
}
