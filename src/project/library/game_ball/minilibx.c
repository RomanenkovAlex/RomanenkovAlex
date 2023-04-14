#include <mlx.h>
#include <math.h>

#define LEFT_ARROW 65361
#define RIGHT_ARROW 65363

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
}				t_vars;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_box()
{}

int	key_hook(int keycode, t_vars *vars)
{
	const double	length_of_sq_x = 250;
	const double 	length_of_sq_y = 50;
	static double	y1_sq = 900;
	static double	x1_sq = 0;
	static double	y2_sq = 850;
	static double	x2_sq = 250;
	static double	x = 0;
	
	if (keycode == LEFT_ARROW)
	{}
	else if (keycode == RIGHT_ARROW)
	{}
	
	for (int i = 0; i < length_of_sq_x; ++i)
	{
		my_mlx_pixel_put(&vars->img,
						 i + x,  	//sin(i) * r + x0,
						 y1_sq,	//cos(i) * r + y0,
						0x00FFFDD0);
		
		my_mlx_pixel_put(&vars->img,
						 i + x,	//sin(i) * r + x0,
						 y2_sq,	//cos(i) * r + y0,
						 0x00FFFDD0);
	}
	for (int i = 0; i < length_of_sq_y; ++i)
	{
		my_mlx_pixel_put(&vars->img,
						 x1_sq + x,  	//sin(i) * r + x0,
						 i + y2_sq,	//cos(i) * r + y0,
						0x00FFFDD0);
		my_mlx_pixel_put(&vars->img,
						 x2_sq + x,  	//sin(i) * r + x0,
						 i + y2_sq,			//cos(i) * r + y0,
						0x00FFFDD0);
	}
	++x1_sq;
	++x2_sq;
	x += 20;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);

	return (0);
}

int	main(void)
{
	t_vars	var;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 1920, 1080, "Hello world!");
	var.img.img = mlx_new_image(var.mlx, 1920, 1080);
	var.img.addr = mlx_get_data_addr(var.img.img,
								 &var.img.bits_per_pixel,
								 &var.img.line_length,
								 &var.img.endian);
	mlx_key_hook(var.win, key_hook, &var);

	mlx_loop(var.mlx);
}

void bad_smile(t_data *img)
{
	for (int i = 0; i < 1920; ++i)
	{
		my_mlx_pixel_put(img, i, 0, 0x00FF0000); // oy
		my_mlx_pixel_put(img, i, 1012, 0x00FF0000);
	}

	for (int i = 0; i < 1080; ++i)
	{
		my_mlx_pixel_put(img, 0, i, 0x00FF0000); // ox
		my_mlx_pixel_put(img, 1919, i, 0x00FF0000);
	}

	for (int i = 0; i < 750; ++i)
	{
		my_mlx_pixel_put(img, i + 500, 580, 0x00FFFDD0);
		my_mlx_pixel_put(img, i + 500, 380, 0x00FFFDD0);
	}

	for (int i = 0; i < 200; ++i)
	{
		my_mlx_pixel_put(img, 1250, i + 380, 0x00FFFDD0);
		my_mlx_pixel_put(img, 500, i + 380, 0x00FFFDD0);
		my_mlx_pixel_put(img, i + 775, 550, 0x00FFFDD0);
		my_mlx_pixel_put(img, i + 550, 450, 0x00FFFDD0);
		my_mlx_pixel_put(img, i + 1000, 450, 0x00FFFDD0);
	}
}
