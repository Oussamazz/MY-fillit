

#include "fillit.h"


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
/* get all positions of tetriminos */

t_tetris	*get_all_tetri(char *line)
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
		tr = get_pos(ft_strsub(line, add21, 20) , letter);
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
	char **result;
	if (tr->next == NULL)
		return (map);
	x = 0;
	result = NULL;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			xy_tetr(&tr, x, y);
			if (check_tetri(map, tr, size))
				result = solver((insert_tetri(map, tr, size)), tr->next, size);
			if (result)
				return (result);
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
	char **result;

	size = ft_sqrt(count_tetri(line) * 4);
	map = tetri_map_init(size);
	result = NULL;
	while (!(result = solver(map, tr, size)))
	{
		size++;
		ft_strdel(map);
		map = tetri_map_init(size);
	}
	print_map(result);
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
