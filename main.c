/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:59:40 by oelazzou          #+#    #+#             */
/*   Updated: 2019/05/10 17:37:59 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     main(int ac, char **av)
{
    	int fd;
    	char *line;
	char *mapi;
	(void)ac;
	t_tetris *tr;
	int i;

	fd = open(av[1], O_RDONLY);
    	if (fd < 0)
        return (-1);
   	 line = read_file(fd);
  	ft_putstr(line);

	ft_putstr("check_all:");
	check_all(line);
	ft_putnbr(1);

	tr = get_pos(line);
    return (0);
}
