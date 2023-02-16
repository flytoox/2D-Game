/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:23:10 by obelaizi          #+#    #+#             */
/*   Updated: 2023/02/16 23:59:34 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <math.h>
# include "../Libft/libft.h"
# include "../gnl/get_next_line.h"
// # include "mlx/mlx.h"
# include <mlx.h>

typedef struct image {
	void	*img;
	int		img_width ;
	int		img_height ;
}				t_img;

typedef struct enemy {
	t_img	enm1;
	t_img	enm2;
	t_img	enm3;
	t_img	enm4;
	t_img	enm5;
	t_img	enm6;
	t_img	enm7;
	t_img	enm8;
	t_img	enm9;
	t_img	enm10;
}				t_enemy;

typedef struct my_game {
	void	*mlx;
	void	*win;
	char	**map;
	t_img	back;
	t_img	clct;
	t_img	plyr;
	t_img	ext;
	t_img	wall;
	t_enemy	enemy;
	int		mvs;
}				t_game;

char	**map_error(char *path);
int		get_y(char **map, char c);
int		get_x(char **map, char c);
int		check_exit(char **map);
int		check_collect(char **map, int check);
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

void	print_enemy(t_game slong, int i, int width, int height);
void	fill_my_enemy(t_game *slong);
int		enemy_animation(t_game *slong);
void	enemy_on_map(t_game slong);

#endif
