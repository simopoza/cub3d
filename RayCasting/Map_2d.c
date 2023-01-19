/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:51:05 by flouta            #+#    #+#             */
/*   Updated: 2023/01/19 01:28:20 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_img(t_infos *data, t_cord *cord , int color) // protect drow image
{
	char    *draw;

	if(cord->x < data->window_width && cord->y < data->window_heigth)
	{
		for(int i = cord->x; i < cord->x  + cord->size ;i++)
		{
			for(int j = cord->y; j <cord->y + cord->size ;j++)
			{
				draw = data->img.img_addr + (j * data->img.bytes_in_row + i * (data->img.bytes_in_px / 8));
				if(cord->size > 1)
				{
					if(cord->size == 0 || (i != 0 && j != 0 && i != cord->x + cord->size - 1 && j != cord->y + cord->size - 1))
						*(int *)draw = color;
					else
						*(int *)draw = 489798;
				}else
					*(int *)draw = color;
			}
		}
	}
}

void render_map(t_infos *data)
{
	int	i = 0;
	int j = 0;
	t_cord cord;

	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			cord.x = j * data->scale;
			cord.y = i * data->scale;
			cord.size = data->scale;
			if(data->map[i][j] == '1')
				draw_img(data, &cord , 0xEEE6E4);
			if(data->map[i][j] == '0' || data->map[i][j] == 'N' ||  data->map[i][j] == 'S' ||  data->map[i][j] == 'E' ||  data->map[i][j] == 'W')//mod
				draw_img(data, &cord , 0x000000);
			j++;
		}
		i++;
	}
}

void create_img(t_infos *wnd)
{
	wnd->img.mlx_img = mlx_new_image(wnd->mlx, wnd->window_width, wnd->window_heigth);
	if(!wnd->img.mlx_img )
		print_error("ERROR: image init failed\n");
	wnd->img.img_addr = mlx_get_data_addr(wnd->img.mlx_img, &wnd->img.bytes_in_px, &wnd->img.bytes_in_row, &wnd->img.endian);
	if(!wnd->img.img_addr )
		print_error("ERROR: image info init failed\n");
}

void destroy_img(t_infos *wnd)
{
	mlx_put_image_to_window(wnd->mlx, wnd->mlx_win, wnd->img.mlx_img, 0, 0);
	mlx_destroy_image(wnd->mlx, wnd->img.mlx_img);
}
int	render(t_infos *wnd)
{
	int i;

	i = 0;

	create_img(wnd);
	// render_map(wnd);
	 render3Dprojection(wnd);
	// while(i < wnd->window_width)
	// {
	// 	drawline(wnd, wnd->player.x_pos , wnd->player.y_pos  ,wnd->rays[i].wall_x , wnd->rays[i].wall_y);
	// 	i++;
	// }
	destroy_img(wnd);
	return (0);
}

void print_error(char *msg)
{
	write(2,msg,ft_strlen(msg));
	exit(1);
}

