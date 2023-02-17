/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:37:06 by obelaizi          #+#    #+#             */
/*   Updated: 2023/02/17 21:49:01 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *slong)
{
	if (keycode == 53 || keycode == 13
		|| keycode == 1 || keycode == 0 || keycode == 2)
	{
		if (keycode == 53)
		{
			mlx_destroy_window(slong->mlx, slong->win);
			exit(0);
		}
		else if (keycode == 13)
			move_up(slong->map, &slong->mvs, *slong);
		else if (keycode == 1)
			move_down(slong->map, &slong->mvs, *slong);
		else if (keycode == 0)
			move_left(slong->map, &slong->mvs, slong);
		else
			move_right(slong->map, &slong->mvs, slong);
		mlx_clear_window(slong->mlx, slong->win);
		map_on_game(slong->map, *slong);
	}
	return (0);
}

int	myclose(t_game *slong)
{
	free_all(slong->map, *slong);
	exit(0);
	return (0);
}

void	fill_my_variable(t_game *slong, int height, int width)
{
	slong->mvs = 0;
	slong->mlx = mlx_init();
	if (!slong->mlx || height * 50 > 8000 || width * 50 > 8000)
	{
		ft_putstr_fd("Error\nThe map is so big dude", 2);
		exit(1);
	}
	slong->win = mlx_new_window(slong->mlx, width * 50, height * 50, "So_Long");
	slong->back.img = mlx_xpm_file_to_image(slong->mlx,
			"./pictures/background.xpm",
			&slong->back.img_width, &slong->back.img_height);
	slong->plyr.img = mlx_xpm_file_to_image(slong->mlx,
			"./pictures/plyrR.xpm",
			&slong->plyr.img_width, &slong->plyr.img_height);
	slong->clct.img = mlx_xpm_file_to_image(slong->mlx, "./pictures/burger.xpm",
			&slong->clct.img_width, &slong->clct.img_height);
	slong->ext.img = mlx_xpm_file_to_image(slong->mlx, "./pictures/exit.xpm",
			&slong->ext.img_width, &slong->ext.img_height);
	slong->wall.img = mlx_xpm_file_to_image(slong->mlx, "./pictures/wall.xpm",
			&slong->wall.img_width, &slong->wall.img_height);
}

int	main(int argc, char **argv)
{
	t_game	slong;
	void	*plyr_l;

	slong.map = map_error((argv[--argc]));
	fill_my_variable(&slong,
		give_me_height(slong.map), ft_strlen(slong.map[0]));
	plyr_l = mlx_xpm_file_to_image(slong.mlx, "./pictures/plyrL.xpm",
			&slong.plyr.img_width, &slong.plyr.img_height);
	if (!slong.clct.img || !slong.ext.img || !slong.wall.img
		|| !slong.plyr.img || !slong.back.img || !plyr_l)
	{
		ft_putstr_fd("Error\nDude a picture isn't there ;)", 2);
		return (free_all(slong.map, slong), 1);
	}
	mlx_destroy_image(slong.mlx, plyr_l);
	map_on_game(slong.map, slong);
	mlx_hook(slong.win, 2, 0, &key_hook, &slong);
	mlx_hook(slong.win, 17, 0, &myclose, &slong);
	mlx_loop(slong.mlx);
	return (0);
}
