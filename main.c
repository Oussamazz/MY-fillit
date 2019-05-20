/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:59:40 by oelazzou          #+#    #+#             */
/*   Updated: 2019/05/20 09:40:48 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     main(int ac, char **av)
{
	char *line;
	int fd;
	t_tetris *tr;
	
	tr = NULL;
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
	tr = get_all_tetri(line);
	solve(3, tr);
	return (0);
}
