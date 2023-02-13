/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:37:06 by obelaizi          #+#    #+#             */
/*   Updated: 2023/02/13 19:43:58 by obelaizi         ###   ########.fr       */
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

int	myclose(void)
{
	exit(0);
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
	slong->plyr.path = ft_strdup("./pictures/SpongebobR.xpm");
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
	map_on_game(slong.map, slong);
	mlx_key_hook(slong.win, &key_hook, &slong);
	mlx_hook(slong.win, 17, 0, &myclose, &slong);
	mlx_loop(slong.mlx);
	return (0);
}
