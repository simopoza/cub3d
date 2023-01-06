/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:51:05 by flouta            #+#    #+#             */
/*   Updated: 2023/01/06 21:32:32 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	map_columns(char **map)
{
	int i;
	int columns;
	int size;

	i = 0;
	columns = 0;
	size = 0;

	while(map[i])
	{
		columns = ft_strlen(map[i]);
		if(columns > size)
			size = columns;
		i++;

	}
	return size;
}

int map_rows(char **map)
{
	int i ;

	i = 0;
	while(map[i])
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
			if(size > 1)
			{
				if(size == 0 || (i != 0 && j != 0 && i != x + size - 1 && j != y + size - 1))
					*(int *)draw = color;
				else
					*(int *)draw = 0x000000;
			}else
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
			if(map[i][j] == '0')
				draw_img(img, j*30, i*30, 0x000000, 30);
			j++;
		}
		i++;
	}
}

int	render(t_infos *wnd)
{
	//move(wnd);
	render_map(&wnd->img, wnd->map);
	render_player(wnd);
	mlx_put_image_to_window(wnd->mlx, wnd->mlx_win, wnd->img.MlxImg, 0, 0);
	return (0);
}

void print_error(char *msg)
{
	write(2,msg,ft_strlen(msg));
	exit(1);
}
void init_window(t_infos *data)
{
	data->WINDOW_WIDTH = map_columns(data->map) * 30;
	data->WINDOW_HEIGHT = map_rows(data->map) * 30;
	data->mlx = mlx_init();
	if(!data->mlx)
		print_error("ERROR: mlx init failed\n");
	data->mlx_win = mlx_new_window(data->mlx,  data->WINDOW_WIDTH,data->WINDOW_HEIGHT, "Cub3d");
	if(!data->mlx_win)
		print_error("ERROR: window init failed\n");
	data->img.MlxImg = mlx_new_image(data->mlx, data->WINDOW_WIDTH, data->WINDOW_HEIGHT);
	if(!data->img.MlxImg )
		print_error("ERROR: image init failed\n");
	data->img.ImgAddr = mlx_get_data_addr(data->img.MlxImg, &data->img.BytesInPx, &data->img.BytesInRow, &data->img.endian);
	if(!data->img.ImgAddr )
		print_error("ERROR: image info init failed\n");
	data->player.x_pos = data->WINDOW_WIDTH/2;
	data->player.y_pos = data->WINDOW_HEIGHT/2;
	data->player.turn_direction = 0;
	data->player.walk_direction = 0;
	data->player.walk_speed = 20;
	data->player.turn_speed = 30 * (M_PI / 180);
	data->player.walk_step = 0;
	data->player.turn_step = M_PI /-2;

}
