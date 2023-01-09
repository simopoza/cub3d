/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 3022/12/23 16:01:48 by mannahri          #+#    #+#             */
/*   Updated: 2023/01/09 18:29:13 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	main(int ac, char *av[])
{
	t_cub	*cub;
	t_infos data;

	cub = parsing(ac, av);

	
	init_window(&data,cub);
	mlx_hook(data.mlx_win, 2, 0, &handle_keypress, &data);
	//calls the user_defined functs when an events occurs
	mlx_loop_hook(data.mlx, &render, &data);
	// mlx_hook(data.mlx_win, 3, 0, &handle_keyrelease, &data);
	//√will  be  called  when  no  event occurs.
	mlx_loop(data.mlx);
	//It is an infinite loop that waits for an event, and then calls a user-defined function associated with this event
	mlx_destroy_window(data.mlx, data.mlx_win);
	free(data.mlx);
	return (0);
}
