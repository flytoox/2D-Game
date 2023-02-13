/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:27:07 by obelaizi          #+#    #+#             */
/*   Updated: 2023/02/13 19:45:41 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(char **map, int	*mvs, t_game slong)
{
	int		x;
	int		y;
	char	*moves;

	x = get_x(map, 'P');
	y = get_y(map, 'P');
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C')
	{
		map[y - 1][x] = 'P';
		map[y][x] = '0';
		moves = ft_itoa(++(*mvs));
		ft_putendl_fd(moves, 1);
		free(moves);
	}
	else if (map[y - 1][x] == 'E' && check_collect(map))
	{
		moves = ft_itoa(++(*mvs));
		ft_putendl_fd(moves, 1);
		free(moves);
		free_all(map, slong);
		exit(0);
	}
}

void	move_down(char **map, int *mvs, t_game slong)
{
	int		x;
	int		y;
	char	*moves;

	x = get_x(map, 'P');
	y = get_y(map, 'P');
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C')
	{
		map[y + 1][x] = 'P';
		map[y][x] = '0';
		moves = ft_itoa(++(*mvs));
		ft_putendl_fd(moves, 1);
		free(moves);
	}
	else if (map[y + 1][x] == 'E' && check_collect(map))
	{
		moves = ft_itoa(++(*mvs));
		ft_putendl_fd(moves, 1);
		free(moves);
		free_all(map, slong);
		exit(0);
	}
}

void	rote_player(t_game *slong, int x)
{
	mlx_destroy_image(slong->mlx, slong->plyr.img);
	free(slong->plyr.path);
	if (x)
		slong->plyr.path = ft_strdup("./pictures/SpongebobL.xpm");
	else
		slong->plyr.path = ft_strdup("./pictures/SpongebobR.xpm");
	slong->plyr.img = mlx_xpm_file_to_image(slong->mlx, slong->plyr.path,
			&slong->plyr.img_width, &slong->plyr.img_height);
}

void	move_right(char **map, int *mvs, t_game *slong)
{
	int		x;
	int		y;
	char	*moves;

	x = get_x(map, 'P');
	y = get_y(map, 'P');
	rote_player(slong, 0);
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C')
	{
		map[y][x + 1] = 'P';
		map[y][x] = '0';
		moves = ft_itoa(++(*mvs));
		ft_putendl_fd(moves, 1);
		free(moves);
	}
	else if (map[y][x + 1] == 'E' && check_collect(map))
	{
		moves = ft_itoa(++(*mvs));
		ft_putendl_fd(moves, 1);
		free(moves);
		free_all(map, *slong);
		exit(0);
	}
}

void	move_left(char **map, int *mvs, t_game *slong)
{
	int		x;
	int		y;
	char	*moves;

	x = get_x(map, 'P');
	y = get_y(map, 'P');
	rote_player(slong, 1);
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C')
	{
		map[y][x - 1] = 'P';
		map[y][x] = '0';
		moves = ft_itoa(++(*mvs));
		ft_putendl_fd(moves, 1);
		free(moves);
	}
	else if (map[y][x - 1] == 'E' && check_collect(map))
	{
		moves = ft_itoa(++(*mvs));
		ft_putendl_fd(moves, 1);
		free(moves);
		free_all(map, *slong);
		exit(0);
	}
}
