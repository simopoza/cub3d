/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 3022/12/23 16:01:48 by mannahri          #+#    #+#             */
/*   Updated: 2023/01/06 21:34:43 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



// int	handle_keypress(int keysym, t_infos *data)
// {
// 	if(keysym == 123)//left
// 		data->player.turn_direction = -1;
// 	if(keysym == 124)//right
// 		data->player.turn_direction = 1;
// 	if(keysym == 125)//down
// 		data->player.walk_direction = -1;
// 	if(keysym == 126)//up
// 		data->player.walk_direction = 1;
// 	move(data);
// 	render(data);
// 	return (0);
// }

int	main(int ac, char *av[])
{
	t_cub	*cub;
	t_infos data;

	cub = parsing(ac, av);
	data.map = cub->the_map;
	init_window(&data);
	//mlx_hook(data.mlx_win, 2, (1L<<0), &handle_keypress, &data);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.mlx_win);
	free(data.mlx);
	return (0);
}

//events
//update
//render