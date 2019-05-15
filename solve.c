

#include "fillit.h"

/* get all positions of all tetriminos */

void	xy_tetr(t_tetris **tr, int x, int y)
{
	int i;
	int min_x;
	int min_y;

	min_x = 11;
	min_y = 11;
	i = 0;
	while (i <= 3)
	{
		if (min_x > (*tr)->x[i])
			min_x = (*tr)->x[i];
		if (min_y > (*tr)->y[i])
			min_y = (*tr)->y[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		(*tr)->x[i] -= min_x + x;
		(*tr)->y[i] -= min_y + y;
		i++;
	}
}

t_tetris	*get_all_tetri(char *line, int size)
{
	t_tetris *tr;
	char letter;
	int add21;
	int tetri_count;
	t_tetris *ret;

	tetri_count = count_tetri(line);
	add21 = 0;
	letter = 'A';
	if(!(tr = (t_tetris*)ft_memalloc(sizeof(t_tetris))))
			return (NULL);
	ret = tr;
	while (tetri_count--)
	{
		tr = get_tetri(&line[add21] , letter);
		letter++;
		add21 += 21;
		if (!(tr->next = (t_tetris*)ft_memalloc(sizeof(t_tetris))))
			return (NULL);
		tr = tr->next;
	}
	return (ret);
}


char	**solver(char **map, t_tetris *tr, int size)
{
	int x;
	int y;
	if (tr->next == NULL)
		return (map);
	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			xy_tetr(&tr, x, y);
			if (check_tetri(map, tr, size))
				map = solver((inser_tetri(map, tr, size)), tr->next, size);
			if (map)
				return map;
			map = remove_tetri(map, tr, size);
			y++;
		}
		x++;
	}
	return (NULL);
}


void	solve(char *line, t_tetris *tr)
{
	int size;
	char **map;

	size = ft_sqrt(count_tetri(line) * 4);
	map = tetri_map_init(size);
	while (!(map = solver(map, tr, size)))
	{
		size++;
		ft_strdel(&map);
		map = tetri_map_init(size);
	}
	print_map(map);
	return ;
}

void	print_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_putendl(map[i]);
		i++;
	}
}
