/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:22:39 by obelaizi          #+#    #+#             */
/*   Updated: 2023/02/17 15:56:12 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	make_it_orgnl(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '3')
				map[i][j] = 'C';
			else if (map[i][j] == '2')
				map[i][j] = '0';
			j++;
		}
		i++;
	}
}

int	check_exit(char **map)
{
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;

	p_x = get_x(map, 'P');
	p_y = get_y(map, 'P');
	e_x = get_x(map, 'E');
	e_y = get_y(map, 'E');
	search(map, p_x, p_y, 0);
	if (map[e_y][e_x + 1] == '2' || map[e_y][e_x - 1] == '2'
		|| map[e_y - 1][e_x] == '2' || map[e_y + 1][e_x] == '2'
		|| map[e_y][e_x + 1] == '3' || map[e_y][e_x - 1] == '3'
		|| map[e_y - 1][e_x] == '3' || map[e_y + 1][e_x] == '3'
		|| map[e_y][e_x + 1] == 'P' || map[e_y][e_x - 1] == 'P'
		|| map[e_y - 1][e_x] == 'P' || map[e_y + 1][e_x] == 'P')
		return (1);
	ft_putstr_fd("Error\nU can't escape, free that exist:)", 2);
	return (0);
}

int	check_collect(char **map, int check)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				if (check)
					ft_putstr_fd("Error\nU can't eat, Cmon do something:)", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

char	**map_error(char *path)
{
	int		fd;
	t_line	*head;
	char	**map;

	head = NULL;
	fd = open(path, O_RDWR);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nDude there no map on that path ;(", 2);
		exit(1);
	}
	if (check_map_name(path) || !check_rectangle(fd, &head)
		|| !check_map_inside(head) || !check_map_closed(head))
		return (0);
	map = fill_dbl_string(head);
	if (!map)
	{
		ft_putstr_fd("Error\nemm", 2);
		exit (1);
	}
	if (!check_exit(map) || !check_collect(map, 1))
		exit (1);
	make_it_orgnl(map);
	ft_lstclear(&head);
	return (map);
}
