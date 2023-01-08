/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 3022/12/23 16:01:48 by mannahri          #+#    #+#             */
/*   Updated: 2023/01/08 01:33:16 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



int	handle_keypress(int keysym, t_infos *data)
{
	int flag;

	flag = 0;
	if(keysym == 13)
		data->player.walk_direction = 1;
	if(keysym == 1)
		data->player.walk_direction = -1;
	if(keysym == 123)
		data->player.turn_direction = -1;
	if(keysym == 124)
		data->player.turn_direction = 1;
	if(keysym == 2)
	{
		data->player.walk_direction = 1;
		flag = 1;
	}
	if(keysym == 0)
	{
		data->player.walk_direction = -1;
		flag = 1;
	}
	move(data,flag);
	return (0);
}

int	handle_keyrelease(int keysym, t_infos *data)
{
	if(keysym == 13)
		data->player.walk_direction = 0;
	if(keysym == 1)
		data->player.walk_direction = 0;
	if(keysym == 123)
		data->player.turn_direction = 0;
	if(keysym == 124)
		data->player.turn_direction = 0;
	if(keysym == 2)
	{
		data->player.walk_direction = 0;
	}
	if(keysym == 0)
	{
		data->player.walk_direction = 0;
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_cub	*cub;
	t_infos data;

	cub = parsing(ac, av);
	data.map = cub->the_map;
	init_window(&data);
	mlx_hook(data.mlx_win, 2, 0, &handle_keypress, &data);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.mlx_win, 3, 0, &handle_keyrelease, &data);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.mlx_win);
	free(data.mlx);
	return (0);
}
