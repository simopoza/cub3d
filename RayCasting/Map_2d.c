/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:51:05 by flouta            #+#    #+#             */
/*   Updated: 2023/01/09 19:23:18 by flouta           ###   ########.fr       */
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
					*(int *)draw = 0x00FF00;
			}else
				*(int *)draw = color;
		}
	}
}

void render_map(t_infos *data)
{
	int	i = 0;
	int j = 0;

	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if(data->map[i][j] == '1')
				draw_img(&data->img, j * data->SCALE, i * data->SCALE, 0xEEE6E4, data->SCALE);
			if(data->map[i][j] == '0' || data->map[i][j] == 'N' ||  data->map[i][j] == 'S' ||  data->map[i][j] == 'E' ||  data->map[i][j] == 'W')//mod
				draw_img(&data->img, j * data->SCALE, i * data->SCALE, 0x000000, data->SCALE);
			j++;
		}
		i++;
	}
}

int	render(t_infos *wnd)
{
	wnd->img.MlxImg = mlx_new_image(wnd->mlx, wnd->WINDOW_WIDTH, wnd->WINDOW_HEIGHT);
	if(!wnd->img.MlxImg )
		print_error("ERROR: image init failed\n");
	wnd->img.ImgAddr = mlx_get_data_addr(wnd->img.MlxImg, &wnd->img.BytesInPx, &wnd->img.BytesInRow, &wnd->img.endian);
	if(!wnd->img.ImgAddr )
		print_error("ERROR: image info init failed\n");
	render_map(wnd);
	render_player(wnd);
	mlx_put_image_to_window(wnd->mlx, wnd->mlx_win, wnd->img.MlxImg, 0, 0);
	mlx_destroy_image(wnd->mlx, wnd->img.MlxImg);
	return (0);
}

void print_error(char *msg)
{
	write(2,msg,ft_strlen(msg));
	exit(1);
}
void init_window(t_infos *data, t_cub *cub)
{
	data->map = cub->the_map;
	data->SCALE = 60;
	data->WINDOW_WIDTH = map_columns(data->map) * data->SCALE;
	data->WINDOW_HEIGHT = map_rows(data->map) *  data->SCALE;
	data->mlx = mlx_init();
	if(!data->mlx)
		print_error("ERROR: mlx init failed\n");
	data->mlx_win = mlx_new_window(data->mlx,  data->WINDOW_WIDTH,data->WINDOW_HEIGHT, "Cub3d");
	if(!data->mlx_win)
		print_error("ERROR: window init failed\n");
	data->player.x_pos = cub->player_pos_x * data->SCALE;
	data->player.y_pos = cub->player_pos_y * data->SCALE;
	data->player.turn_direction = 0;
	data->player.walk_direction = 0;
	data->player.walk_speed = 5;
	data->player.turn_speed = 10 * (M_PI/180);
	data->player.walk_step = 0;
	if(data->map[cub->player_pos_y][cub->player_pos_x] == 'N')
		data->player.turn_step =-( 90 * (M_PI/180));
	if(data->map[cub->player_pos_y][cub->player_pos_x] == 'S')
		data->player.turn_step = 90 * (M_PI/180);
	if(data->map[cub->player_pos_y][cub->player_pos_x] == 'E')
		data->player.turn_step = 0 * (M_PI/180);
	if(data->map[cub->player_pos_y][cub->player_pos_x] == 'W')
		data->player.turn_step = 180 * (M_PI/180);
}
