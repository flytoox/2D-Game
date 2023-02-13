/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:23:10 by obelaizi          #+#    #+#             */
/*   Updated: 2023/02/13 19:48:52 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include "../Libft/libft.h"
# include "../gnl/get_next_line.h"
// # include "mlx/mlx.h"
# include <mlx.h>

typedef struct image {
	void	*img;
	int		img_width ;
	int		img_height ;
	char	*path;
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
int		check_exit(char **map);
int		check_collect(char **map);
int		check_map_name(char *path);
int		count_char(const char *s, char c);
int		check_rectangle(int fd, t_line **head);
int		check_line_valid(char *src, const char *check);
int		check_map_inside(t_line *head);
int		first_last_1(char *str);
int		check_map_closed(t_line *head);
char	*fill_untl_nl(char *str);
void	free_str(char **str, int i);
char	**fill_dbl_string(t_line *head);
void	search(char **map, int x, int y, int check);
int		give_me_height(char	**map);
void	free_map(char **map);

void	free_all(char **map, t_game slong);
void	mlx_img_wndw(t_game slong, int width, int height, char c);
void	back_on_game(char **map, t_game slong);
void	map_on_game(char **map, t_game slong);
void	move_up(char **map, int	*mvs, t_game slong);
void	move_down(char **map, int *mvs, t_game slong);
void	move_right(char **map, int *mvs, t_game *slong);
void	move_left(char **map, int *mvs, t_game *slong);

#endif
