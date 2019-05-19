

#include "fillit.h"


void	xy_tetr(t_tetris **tr, int x, int y)
{
	int i;
	int min_x;
	int min_y;

	min_x = 11;
	min_y = 11;
	i = 0;
	while (i < 4)
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
	x = 0;
	result = NULL;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			xy_tetr(&tr, y, x);
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
