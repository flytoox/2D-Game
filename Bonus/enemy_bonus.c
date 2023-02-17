/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:28:40 by obelaizi          #+#    #+#             */
/*   Updated: 2023/02/17 15:31:38 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fill_my_enemy_helper(t_game *slong)
{
	if (!slong->enemy.enm1.img || !slong->enemy.enm2.img
		|| !slong->enemy.enm3.img || !slong->enemy.enm4.img
		|| !slong->enemy.enm5.img || !slong->enemy.enm6.img
		|| !slong->enemy.enm7.img)
	{
		ft_putstr_fd("Error\nDude a picture isn't there ;)", 2);
		free_all(slong->map, *slong);
		exit(1);
	}
}

void	fill_my_enemy(t_game *slong)
{
	slong->enemy.enm1.img = mlx_xpm_file_to_image(slong->mlx,
			"./Bonus/enemy/1.xpm",
			&slong->enemy.enm1.img_width, &slong->enemy.enm1.img_height);
	slong->enemy.enm2.img = mlx_xpm_file_to_image(slong->mlx,
			"./Bonus/enemy/2.xpm",
			&slong->enemy.enm2.img_width, &slong->enemy.enm2.img_height);
	slong->enemy.enm3.img = mlx_xpm_file_to_image(slong->mlx,
			"./Bonus/enemy/3.xpm", &slong->enemy.enm3.img_width,
			&slong->enemy.enm3.img_height);
	slong->enemy.enm4.img = mlx_xpm_file_to_image(slong->mlx,
			"./Bonus/enemy/4.xpm", &slong->enemy.enm4.img_width,
			&slong->enemy.enm4.img_height);
	slong->enemy.enm5.img = mlx_xpm_file_to_image(slong->mlx,
			"./Bonus/enemy/5.xpm", &slong->enemy.enm5.img_width,
			&slong->enemy.enm5.img_height);
	slong->enemy.enm6.img = mlx_xpm_file_to_image(slong->mlx,
			"./Bonus/enemy/6.xpm", &slong->enemy.enm6.img_width,
			&slong->enemy.enm6.img_height);
	slong->enemy.enm7.img = mlx_xpm_file_to_image(slong->mlx,
			"./Bonus/enemy/7.xpm", &slong->enemy.enm7.img_width,
			&slong->enemy.enm7.img_height);
	fill_my_enemy_helper(slong);
}

int	enemy_animation(t_game *slong)
{
	mlx_clear_window(slong->mlx, slong->win);
	map_on_game(slong->map, *slong);
	enemy_on_map(*slong);
	return (0);
}

void	print_enemy(t_game slong, int i, int width, int height)
{
	if (i == 0)
		mlx_put_image_to_window(slong.mlx, slong.win,
			slong.enemy.enm1.img, width, height);
	else if (i <= 5)
		mlx_put_image_to_window(slong.mlx, slong.win,
			slong.enemy.enm2.img, width, height);
	else if (i <= 10)
		mlx_put_image_to_window(slong.mlx, slong.win,
			slong.enemy.enm3.img, width, height);
	else if (i <= 15)
		mlx_put_image_to_window(slong.mlx, slong.win,
			slong.enemy.enm4.img, width, height);
	else if (i <= 20)
		mlx_put_image_to_window(slong.mlx, slong.win,
			slong.enemy.enm5.img, width, height);
	else if (i <= 25)
		mlx_put_image_to_window(slong.mlx, slong.win,
			slong.enemy.enm6.img, width, height);
	else if (i < 30)
		mlx_put_image_to_window(slong.mlx, slong.win,
			slong.enemy.enm7.img, width, height);
}
