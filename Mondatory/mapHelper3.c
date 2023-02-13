/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapHelper3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:17:38 by obelaizi          #+#    #+#             */
/*   Updated: 2023/02/12 16:28:44 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_x(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				return (j);
			j++;
		}
		i++;
	}
	return (2147483647);
}

int	get_y(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				return (i);
			j++;
		}
		i++;
	}
	return (2147483647);
}

void	search_helper(char **map, int x, int y)
{
	if (map[y][x] == '0')
		map[y][x] = '2';
	else
		map[y][x] = '3';
}

void	search(char **map, int x, int y, int check)
{
	if ((map[y][x + 1] == '0' || map[y][x + 1] == 'C') && check != 2)
	{
		search_helper(map, x + 1, y);
		search(map, x + 1, y, 1);
	}
	if ((map[y][x - 1] == '0' || map[y][x - 1] == 'C') && check != 1)
	{
		search_helper(map, x - 1, y);
		search(map, x - 1, y, 2);
	}
	if ((map[y - 1][x] == '0' || map[y - 1][x] == 'C') && check != 4)
	{
		search_helper(map, x, y - 1);
		search(map, x, y - 1, 3);
	}
	if ((map[y + 1][x] == '0' || map[y + 1][x] == 'C') && check != 3)
	{
		search_helper(map, x, y + 1);
		search(map, x, y + 1, 4);
	}
}

int	give_me_height(char	**map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
