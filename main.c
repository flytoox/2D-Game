/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:37:06 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/31 21:23:44 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	myclose(int keycode, t_game *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	return (0);
// }

int	give_me_height(char	**map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_all(char **map, t_game slong)
{
	free_map(map);
	free(slong.back.path);
	free(slong.plyr.path);
	free(slong.ext.path);
	free(slong.clct.path);
	free(slong.wall.path);
	if (slong.back.img)
		mlx_destroy_image(slong.mlx, slong.back.img);
	if (slong.ext.img)
		mlx_destroy_image(slong.mlx, slong.ext.img);
	if (slong.plyr.img)
		mlx_destroy_image(slong.mlx, slong.plyr.img);
	if (slong.clct.img)
		mlx_destroy_image(slong.mlx, slong.clct.img);
	if (slong.wall.img)
		mlx_destroy_image(slong.mlx, slong.wall.img);
	if (slong.win)
		mlx_destroy_window(slong.mlx, slong.win);
	mlx_destroy_display(slong.mlx);
	free(slong.mlx);
}

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

void	move_right(char **map, int *mvs, t_game slong)
{
	int		x;
	int		y;
	char	*moves;

	x = get_x(map, 'P');
	y = get_y(map, 'P');
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
		free_all(map, slong);
		exit(0);
	}
}

void	move_left(char **map, int *mvs, t_game slong)
{
	int		x;
	int		y;
	char	*moves;

	x = get_x(map, 'P');
	y = get_y(map, 'P');
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
		free_all(map, slong);
		exit(0);
	}
}

int	mlx_img_wndw(t_game slong, int width, int height, char c)
{
	if (c == 'C')
		mlx_put_image_to_window(slong.mlx, slong.win,
			slong.clct.img, width, height);
	else if (c == 'E')
		mlx_put_image_to_window(slong.mlx, slong.win,
			slong.ext.img, width, height);
	else if (c == 'P')
		mlx_put_image_to_window(slong.mlx, slong.win,
			slong.plyr.img, width, height);
	else if (c == '1')
		mlx_put_image_to_window(slong.mlx, slong.win,
			slong.wall.img, width, height);
	else if (c == '0')
		mlx_put_image_to_window(slong.mlx, slong.win,
			slong.back.img, width, height);
}

void	map_on_game(char **map, t_game slong)
{
	int	i;
	int	height;
	int	j;
	int	width;

	i = -1;
	height = 0;
	while (map[++i])
	{
		width = 0;
		j = -1;
		while (map[i][++j])
		{
			mlx_img_wndw(slong, width, height, map[i][j]);
			width += 50;
		}
		height += 50;
	}
}

int	key_hook(int keycode, t_game *slong)
{
	if (keycode == 65307 || keycode == 'w'
		|| keycode == 's' || keycode == 'a' || keycode == 'd')
	{
		if (keycode == 65307)
		{
			mlx_destroy_window(slong->mlx, slong->win);
			exit(0);
		}
		else if (keycode == 'w')
			move_up(slong->map, &slong->mvs, *slong);
		else if (keycode == 's')
			move_down(slong->map, &slong->mvs, *slong);
		else if (keycode == 'a')
			move_left(slong->map, &slong->mvs, *slong);
		else
			move_right(slong->map, &slong->mvs, *slong);
		mlx_clear_window(slong->mlx, slong->win);
		map_on_game(slong->map, *slong);
	}
	return (0);
}

void	fill_my_variable(t_game *slong)
{
	int	height;
	int	width;

	height = give_me_height(slong->map);
	width = ft_strlen(slong->map[0]);
	slong->mvs = 0;
	slong->mlx = mlx_init();
	slong->win = mlx_new_window(slong->mlx, width * 50,
			height * 50, "Hello world!");
	slong->ext.path = ft_strdup("./pictures/exit.xpm");
	slong->clct.path = ft_strdup("./pictures/burger.xpm");
	slong->back.path = ft_strdup("./pictures/background.xpm");
	slong->plyr.path = ft_strdup("./pictures/spongebob.xpm");
	slong->wall.path = ft_strdup("./pictures/wall.xpm");
	slong->back.img = mlx_xpm_file_to_image(slong->mlx, slong->back.path,
			&slong->back.img_width, &slong->back.img_height);
	slong->plyr.img = mlx_xpm_file_to_image(slong->mlx, slong->plyr.path,
			&slong->plyr.img_width, &slong->plyr.img_height);
	slong->clct.img = mlx_xpm_file_to_image(slong->mlx, slong->clct.path,
			&slong->clct.img_width, &slong->clct.img_height);
	slong->ext.img = mlx_xpm_file_to_image(slong->mlx, slong->ext.path,
			&slong->ext.img_width, &slong->ext.img_height);
	slong->wall.img = mlx_xpm_file_to_image(slong->mlx, slong->wall.path,
			&slong->wall.img_width, &slong->wall.img_height);
}

int	main(int argc, char **argv)
{
	t_game	slong;

	slong.map = map_error((argv[--argc]));
	if (!slong.map)
		return (printf("wtf"), 0);
	fill_my_variable(&slong);
	if (!slong.clct.img || !slong.ext.img || !slong.wall.img
		|| !slong.plyr.img || !slong.back.img)
		return (free_all(slong.map, slong), 1);
	slong.plyr.addr = mlx_get_data_addr(slong.plyr.img, &slong.plyr.bts_perpxls,
			&slong.plyr.line_length, &slong.plyr.endian);
	slong.back.addr = mlx_get_data_addr(slong.back.img, &slong.back.bts_perpxls,
			&slong.back.line_length, &slong.back.endian);
	slong.clct.addr = mlx_get_data_addr(slong.clct.img, &slong.clct.bts_perpxls,
			&slong.clct.line_length, &slong.clct.endian);
	slong.ext.addr = mlx_get_data_addr(slong.ext.img, &slong.ext.bts_perpxls,
			&slong.ext.line_length, &slong.ext.endian);
	slong.wall.addr = mlx_get_data_addr(slong.wall.img, &slong.wall.bts_perpxls,
			&slong.wall.line_length, &slong.wall.endian);
	map_on_game(slong.map, slong);
	mlx_key_hook(slong.win, key_hook, &slong);
	mlx_loop(slong.mlx);
}
