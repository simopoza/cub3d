/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:30:53 by flouta            #+#    #+#             */
/*   Updated: 2023/01/19 01:27:55 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_player(t_infos *data, t_cub *cub)
{
	data->player.x_pos = cub->player_pos_x * data->scale ;
	data->player.y_pos = cub->player_pos_y * data->scale ;
	data->player.turn_direction = 0;
	data->player.walk_direction = 0;
	data->player.walk_speed = 5;
	data->player.turn_speed = 5 * (M_PI / 180);
	data->player.walk_step = 0;
	data->player.view = 60 * (M_PI / 180);
	if (data->map[cub->player_pos_y][cub->player_pos_x] == 'N')
		data->player.angle = - (90 * (M_PI / 180));
	if (data->map[cub->player_pos_y][cub->player_pos_x] == 'S')
		data->player.angle = 90 * (M_PI / 180);
	if (data->map[cub->player_pos_y][cub->player_pos_x] == 'E')
		data->player.angle = 0 * (M_PI / 180);
	if (data->map[cub->player_pos_y][cub->player_pos_x] == 'W')
		data->player.angle = 180 * (M_PI / 180);
}

void	init_rays(t_infos *data)
{
	data->rays = (t_ray *)malloc(sizeof(t_ray) * data->window_width);
	if (!data->rays)
		print_error("ERROR: dynamic allocation failure\n");
	cast_all_rays(data);
}

void	init_window(t_infos *data)
{
	data->scale = 32;
	data->window_width = 1200;
	data->window_heigth = 1200;
	data->mlx = mlx_init();
	if (!data->mlx)
		print_error("ERROR: mlx init failed\n");
	data->mlx_win = mlx_new_window(data->mlx, data->window_width, \
		data->window_heigth, "Cub3d");
	if (!data->mlx_win)
		print_error("ERROR: window init failed\n");
}

void	init_start(t_infos *data, t_cub *cub)
{
	data->map = cub->the_map;
	data->rows = cub->rows;
	data->row_len = cub->len_lines;
	init_window(data);
	init_player(data, cub);
	init_rays(data);
}
