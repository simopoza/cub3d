/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:51:05 by flouta            #+#    #+#             */
/*   Updated: 2023/01/18 18:18:13 by mannahri         ###   ########.fr       */
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

void	draw_img(t_img *img, int x, int y, int color , int size, t_infos *wnd)
{
	char    *draw;
	if(y < wnd->window_height  &&  x < wnd->window_width)
	{
		for(int i = x; i < x  + size ;i++)
		{
			for(int j = y; j <y + size ;j++)
			{
				draw = img->img_addr + (j * img->bytes_in_row + i * (img->bytes_in_px / 8));
				if(size > 1)
				{
					if(size == 0 || (i != 0 && j != 0 && i != x + size - 1 && j != y + size - 1))
						*(int *)draw = color;
					else
						*(int *)draw = 489798;
				}
				else
					*(int *)draw = color;
			}
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
				draw_img(&data->img, j * data->scale, i * data->scale, 0xEEE6E4, data->scale, data);
			if(data->map[i][j] == '0' || data->map[i][j] == 'N' ||  data->map[i][j] == 'S' ||  data->map[i][j] == 'E' ||  data->map[i][j] == 'W')//mod
				draw_img(&data->img, j * data->scale, i * data->scale, 0x000000, data->scale, data);
			j++;
		}
		i++;
	}
}

int	render(t_infos *wnd)
{
	wnd->img.mlx_img = mlx_new_image(wnd->mlx, wnd->window_width, wnd->window_height);
	if(!wnd->img.mlx_img)
		print_error("ERROR: image init failed\n");
	wnd->img.img_addr = mlx_get_data_addr(wnd->img.mlx_img, &wnd->img.bytes_in_px, &wnd->img.bytes_in_row, &wnd->img.endian);
	if(!wnd->img.img_addr )
		print_error("ERROR: image info init failed\n");
	// render_map(wnd);
	render3dprojection(wnd);
	
	// int i = 0;
	// while(i < wnd->window_width)
	// {
	// 	drawline(wnd, wnd->player.x_pos , wnd->player.y_pos  ,wnd->rays[i].wall_x , wnd->rays[i].wall_y);
	// 	i++;
	// }
	// render_player(wnd);
	mlx_put_image_to_window(wnd->mlx, wnd->mlx_win, wnd->img.mlx_img, 0, 0);
	mlx_destroy_image(wnd->mlx, wnd->img.mlx_img);
	return (0);
}

void print_error(char *msg)
{
	write(2,msg,ft_strlen(msg));
	exit(1);
}
void init_window(t_infos *data, t_cub *cub)
{
	//init window
	data->map = cub->the_map;
	data->scale = 80;
	// data->window_width = map_columns(data->map) * data->scale;
	data->window_height = 1700;
	data->window_width = 1400;
	// data->window_height = map_rows(data->map) *  data->scale;
	data->mlx = mlx_init();
	if(!data->mlx)
		print_error("ERROR: mlx init failed\n");
	data->mlx_win = mlx_new_window(data->mlx,  data->window_width,data->window_height, "Cub3d");
	if(!data->mlx_win)
		print_error("ERROR: window init failed\n");
	//init player
	data->player.x_pos = cub->player_pos_x * data->scale ;
	data->player.y_pos = cub->player_pos_y * data->scale ;
	data->player.turn_direction = 0;
	data->player.walk_direction = 0;
	data->player.walk_speed = 5;
	data->player.turn_speed = 5 * (M_PI/180);
	data->player.walk_step = 0;
	data->player.view = 60 * (M_PI / 180);
	if(data->map[cub->player_pos_y][cub->player_pos_x] == 'N')
		data->player.angle =-( 90 * (M_PI/180));
	if(data->map[cub->player_pos_y][cub->player_pos_x] == 'S')
		data->player.angle = 90 * (M_PI/180);
	if(data->map[cub->player_pos_y][cub->player_pos_x] == 'E')
		data->player.angle = 0 * (M_PI/180);
	if(data->map[cub->player_pos_y][cub->player_pos_x] == 'W')
		data->player.angle = 180 * (M_PI/180);
	//init rays
	data->rays = (t_ray *)malloc(sizeof(t_ray) * data->window_width );
	if(!data->rays)
		print_error("ERROR: dynamic allocation failure\n");
	cast_all_rays(data);
}
