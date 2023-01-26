#include "mlx/mlx.h"
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 720, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	int i =5, j = 5;
	while (i++ < 50)
	{	j = 5;
		while (j++ < 30)
			my_mlx_pixel_put(&img, i, j, 0x00FF0000);

	}
	// mlx_pixel_put(mlx, mlx_win, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 1, 0);
	mlx_loop(mlx);
}