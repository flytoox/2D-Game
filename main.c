/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:37:06 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/29 22:09:07 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_data {
	void	*img;
	int		img_width ;
	int		img_height ;
	char	*addr;
	char	*path;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	myclose(int keycode, t_vars *vars)
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

int	key_hook(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_data	back;
	t_data	clct;
	t_data	plyr;
	t_data	ext;
	t_data	wall;
	char	**map;
	int		height;
	int		width;

	map = map_error(*(++argv));
	if (!map)
	{
		printf("wtf");
		return (0);
	}
	height = give_me_height(map);
	width = ft_strlen(map[0]);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, width * 50, height * 50, "Hello world!");
	ext.path = ft_strdup("./pictures/exit.xpm");
	clct.path = ft_strdup("./pictures/burger.xpm");
	back.path = ft_strdup("./pictures/background.xpm");
	plyr.path = ft_strdup("./pictures/spongebob.xpm");
	wall.path = ft_strdup("./pictures/wall.xpm");
	back.img = mlx_xpm_file_to_image(vars.mlx, back.path, &back.img_width, &back.img_height);
	back.addr = mlx_get_data_addr(back.img, &back.bits_per_pixel, &back.line_length,
								&back.endian);


	plyr.img = mlx_xpm_file_to_image(vars.mlx, plyr.path, &plyr.img_width, &plyr.img_height);
	plyr.addr = mlx_get_data_addr(plyr.img, &plyr.bits_per_pixel, &plyr.line_length,
								&plyr.endian);


	clct.img = mlx_xpm_file_to_image(vars.mlx, clct.path, &clct.img_width, &clct.img_height);
	clct.addr = mlx_get_data_addr(clct.img, &clct.bits_per_pixel, &clct.line_length,
								&clct.endian);


	ext.img = mlx_xpm_file_to_image(vars.mlx, ext.path, &ext.img_width, &ext.img_height);
	ext.addr = mlx_get_data_addr(ext.img, &ext.bits_per_pixel, &ext.line_length,
								&ext.endian);

	wall.img = mlx_xpm_file_to_image(vars.mlx, wall.path, &wall.img_width, &wall.img_height);
	wall.addr = mlx_get_data_addr(wall.img, &wall.bits_per_pixel, &wall.line_length,
								&wall.endian);
	int i = 0, j;
	height = 0;
	while (map[i])
	{
		width = 0;
		j = 0;
		while (map[i][j])
		{
			mlx_put_image_to_window(vars.mlx, vars.win, back.img, width, height);
			j++;
			width += 50;
		}
		height += 50;
		i++;
	}

	i = 0;
	height = 0;
	while (map[i])
	{
		width = 0;
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				mlx_put_image_to_window(vars.mlx, vars.win, clct.img, width, height);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(vars.mlx, vars.win, ext.img, width, height);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(vars.mlx, vars.win, plyr.img, width, height);
			else if (map[i][j] == '1')
				mlx_put_image_to_window(vars.mlx, vars.win, wall.img, width, height);
			j++;
			width += 50;
		}
		height += 50;
		i++;
	}
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
