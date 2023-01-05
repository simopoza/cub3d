#include "../cub3d.h"

int	map_columns(t_cub *cub)
{
	int i;
	int columns;
	int size;

	i = 0;
	columns = 0;
	size = 0;

	while(cub->the_map[i])
	{
		columns = ft_strlen(cub->the_map[i]);
		if(columns > size)
			size = columns;
		i++;

	}
	return size;
}

int map_rows(t_cub *cub)
{
	int i ;

	i = 0;
	while(cub->the_map[i])
		i++;
	return i;
}

void	draw_img(t_img *img, int x, int y, int color , int size)
{
	char    *draw;

	for(int i = x; i < x  + size ;i++)
	{
		for(int j = y; j <y + size ;j++)
		{
			draw = img->ImgAddr + (j * img->BytesInRow + i * (img->BytesInPx / 8));
			if(i != 0 && j != 0 && i != x + size - 1 && j != y + size - 1)
				*(int *)draw = color;
		}
	}
}

void render_map(t_img *img, char **map)
{
	int	i = 0;
	int j = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if(map[i][j] == '1')
				draw_img(img, j*30, i*30, 0xEEE6E4, 30);
			j++;
		}
		i++;
	}
}

void render_player(t_window *wnd)
{
	draw_img(&wnd->img, wnd->WINDOW_WIDTH/2, wnd->WINDOW_HEIGHT/2, 0xFF0000, 10);
}

int	render(t_window *wnd)
{
	render_map(&wnd->img, wnd->cub->the_map);
	render_player(wnd);
	mlx_put_image_to_window(wnd->mlx, wnd->mlx_win, wnd->img.MlxImg, 0, 0);
	return (0);
}

void print_error(char *msg)
{
	write(2,msg,ft_strlen(msg));
	exit(1);
}
void init_window(t_window *window)
{
	window->WINDOW_WIDTH = map_columns(window->cub) * 30;
	window->WINDOW_HEIGHT = map_rows(window->cub) * 30;
	window->mlx = mlx_init();
	if(!window->mlx)
		print_error("ERROR: mlx init failed\n");
	window->mlx_win = mlx_new_window(window->mlx,  window->WINDOW_WIDTH,window->WINDOW_HEIGHT, "Cub3d");
	if(!window->mlx_win)
		print_error("ERROR: window init failed\n");
	window->img.MlxImg = mlx_new_image(window->mlx, window->WINDOW_WIDTH, window->WINDOW_HEIGHT);
	if(!window->img.MlxImg )
		print_error("ERROR: image init failed\n");
	window->img.ImgAddr = mlx_get_data_addr(window->img.MlxImg, &window->img.BytesInPx, &window->img.BytesInRow, &window->img.endian);
	if(!window->img.ImgAddr )
		print_error("ERROR: image info init failed\n");
}
