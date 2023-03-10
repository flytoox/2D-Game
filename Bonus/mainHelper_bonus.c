/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainHelper_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:29:28 by obelaizi          #+#    #+#             */
/*   Updated: 2023/02/17 21:11:21 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_enemy(t_game slong)
{
	if (slong.enemy.enm1.img)
		mlx_destroy_image(slong.mlx, slong.enemy.enm1.img);
	if (slong.enemy.enm2.img)
		mlx_destroy_image(slong.mlx, slong.enemy.enm2.img);
	if (slong.enemy.enm3.img)
		mlx_destroy_image(slong.mlx, slong.enemy.enm3.img);
	if (slong.enemy.enm4.img)
		mlx_destroy_image(slong.mlx, slong.enemy.enm4.img);
	if (slong.enemy.enm5.img)
		mlx_destroy_image(slong.mlx, slong.enemy.enm5.img);
	if (slong.enemy.enm6.img)
		mlx_destroy_image(slong.mlx, slong.enemy.enm6.img);
	if (slong.enemy.enm7.img)
		mlx_destroy_image(slong.mlx, slong.enemy.enm7.img);
}

void	free_all(char **map, t_game slong)
{
	free_map(map);
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
	free_enemy(slong);
}

void	mlx_img_wndw(t_game slong, int width, int height, char c)
{
	if (c == 'C')
		mlx_put_image_to_window(slong.mlx, slong.win,
			slong.clct.img, width, height);
	else if (c == 'E')
		mlx_put_image_to_window(slong.mlx, slong.win,
			slong.ext.img, width, height);
	else if (c == 'P')
	{
		mlx_put_image_to_window(slong.mlx, slong.win,
			slong.plyr.img, width, height);
	}
	else if (c == '1')
		mlx_put_image_to_window(slong.mlx, slong.win,
			slong.wall.img, width, height);
}

void	back_on_game(char **map, t_game slong)
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
			if (map[i][j] != 1)
				mlx_put_image_to_window(slong.mlx, slong.win,
					slong.back.img, width, height);
			width += 50;
		}
		height += 50;
	}
}

void	map_on_game(char **map, t_game slong)
{
	int		i;
	int		height;
	int		j;
	int		width;
	char	*mvs;

	i = -1;
	height = 0;
	back_on_game(map, slong);
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
	mvs = ft_itoa(slong.mvs);
	mlx_string_put(slong.mlx, slong.win, 0, 0, 16777215, mvs);
	free(mvs);
}
