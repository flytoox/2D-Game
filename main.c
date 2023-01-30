/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:37:06 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/30 22:00:58 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	myclose(int keycode, t_game *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	give_me_height(char	**map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}


void	move_up(char **map, int	*mvs)
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
		moves = ft_itoa(*mvs += 1);
		ft_putendl_fd(moves, 1);
	}
	else if (map[y - 1][x] == 'E' && check_collect(map))
		exit(0);

}

void	move_down(char **map, int *mvs)
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
		moves = ft_itoa(*mvs += 1);
		ft_putendl_fd(moves, 1);
	}
	else if (map[y + 1][x] == 'E' && check_collect(map))
		exit(0);
}

void	move_right(char **map, int *mvs)
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
		moves = ft_itoa(*mvs += 1);
		ft_putendl_fd(moves, 1);
	}
	else if (map[y][x + 1] == 'E' && check_collect(map))
		exit(0);
}

void	move_left(char **map, int *mvs)
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
		moves = ft_itoa(*mvs += 1);
		ft_putendl_fd(moves, 1);
	}
	else if (map[y][x - 1] == 'E' && check_collect(map))
		exit(0);
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
			if (map[i][j] == 'C')
				mlx_put_image_to_window(slong.mlx, slong.win, slong.clct.img, width, height);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(slong.mlx, slong.win, slong.ext.img, width, height);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(slong.mlx, slong.win, slong.plyr.img, width, height);
			else if (map[i][j] == '1')
				mlx_put_image_to_window(slong.mlx, slong.win, slong.wall.img, width, height);
			width += 50;
		}
		height += 50;
	}
}

int	key_hook(int keycode, t_game *slong)
{
	char	*mvs;

	if (keycode == 65307 || keycode == 'w' || keycode == 's' || keycode == 'a' || keycode == 'd')
	{
		if (keycode == 65307)
		{
			mlx_destroy_window(slong->mlx, slong->win);
			exit(0);
		}
		else if (keycode == 'w')
			move_up(slong->map, &slong->mvs);
		else if (keycode == 's')
			move_down(slong->map, &slong->mvs);
		else if (keycode == 'a')
			move_left(slong->map, &slong->mvs);
		else
			move_right(slong->map, &slong->mvs);
		mlx_clear_window(slong->mlx, slong->win);
		map_on_game(slong->map, *slong);
	}
	// printf("%d\n", keycode);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	slong;
	int		height;
	int		width;

	slong.map = map_error(*(++argv));
	if (!slong.map)
		return (printf("wtf"), 0);

	height = give_me_height(slong.map);
	width = ft_strlen(slong.map[0]);
	slong.mvs = 0;
	slong.mlx = mlx_init();
	slong.win = mlx_new_window(slong.mlx, width * 50, height * 50, "Hello world!");
	slong.ext.path = ft_strdup("./pictures/exit.xpm");
	slong.clct.path = ft_strdup("./pictures/burger.xpm");
	slong.back.path = ft_strdup("./pictures/background.xpm");
	slong.plyr.path = ft_strdup("./pictures/spongebob.xpm");
	slong.wall.path = ft_strdup("./pictures/wall.xpm");
	slong.back.img = mlx_xpm_file_to_image(slong.mlx, slong.back.path, &slong.back.img_width, &slong.back.img_height);
	slong.back.addr = mlx_get_data_addr(slong.back.img, &slong.back.bits_per_pixel, &slong.back.line_length,
								&slong.back.endian);


	slong.plyr.img = mlx_xpm_file_to_image(slong.mlx, slong.plyr.path, &slong.plyr.img_width, &slong.plyr.img_height);
	slong.plyr.addr = mlx_get_data_addr(slong.plyr.img, &slong.plyr.bits_per_pixel, &slong.plyr.line_length,
								&slong.plyr.endian);


	slong.clct.img = mlx_xpm_file_to_image(slong.mlx, slong.clct.path, &slong.clct.img_width, &slong.clct.img_height);
	slong.clct.addr = mlx_get_data_addr(slong.clct.img, &slong.clct.bits_per_pixel, &slong.clct.line_length,
								&slong.clct.endian);


	slong.ext.img = mlx_xpm_file_to_image(slong.mlx, slong.ext.path, &slong.ext.img_width, &slong.ext.img_height);
	slong.ext.addr = mlx_get_data_addr(slong.ext.img, &slong.ext.bits_per_pixel, &slong.ext.line_length,
								&slong.ext.endian);

	slong.wall.img = mlx_xpm_file_to_image(slong.mlx, slong.wall.path, &slong.wall.img_width, &slong.wall.img_height);
	slong.wall.addr = mlx_get_data_addr(slong.wall.img, &slong.wall.bits_per_pixel, &slong.wall.line_length,
								&slong.wall.endian);
	// int i = 0, j;
	// height = 0;
	// while (slong.map[i])
	// {
	// 	width = 0;
	// 	j = 0;
	// 	while (slong.map[i][j])
	// 	{
	// 		mlx_put_image_to_window(slong.mlx, slong.win, slong.back.img, width, height);
	// 		j++;
	// 		width += 50;
	// 	}
	// 	height += 50;
	// 	i++;
	// }

	map_on_game(slong.map, slong);
	mlx_key_hook(slong.win, key_hook, &slong);
	mlx_loop(slong.mlx);
}
