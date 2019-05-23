/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:59:40 by oelazzou          #+#    #+#             */
/*   Updated: 2019/05/23 21:40:26 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int			fd;
	int			size;
	char		*line;
	t_tetris	*tr;

	size = 0;
	tr = NULL;
	if (ac != 2)
	{
		ft_putendl_fd("usage: ./fillit file", 1);
		exit(EXIT_SUCCESS);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit_error();
	line = read_file(fd);
	check_all(line);
	tr = get_all_tetri(line);
	size = ft_sqrt(count_tetri(line) * 4);
	solve(size, tr);
	return (0);
}
