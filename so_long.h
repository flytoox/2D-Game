/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:23:10 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/31 21:24:34 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include "Libft/libft.h"
# include "gnl/get_next_line.h"
# include "mlx/mlx.h"

typedef struct image {
	void	*img;
	int		img_width ;
	int		img_height ;
	char	*addr;
	char	*path;
	int		bts_perpxls;
	int		line_length;
	int		endian;
}				t_img;

typedef struct my_game {
	void	*mlx;
	void	*win;
	char	**map;
	t_img	back;
	t_img	clct;
	t_img	plyr;
	t_img	ext;
	t_img	wall;
	int		mvs;
}				t_game;

char	**map_error(char *path);
int		get_y(char **map, char c);
int		get_x(char **map, char c);
int		check_collect(char **map);

#endif
