/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 3022/12/23 16:01:48 by mannahri          #+#    #+#             */
/*   Updated: 2023/01/19 01:56:34 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char *av[])
{
	t_cub	*cub;
	t_infos	data;

	cub = parsing(ac, av);
	init_start(&data, cub);
	if (!cub->rgb_f)
		data.floor = (cub->rgb_f[0] << 16 | cub->rgb_f[1] << 8 | cub->rgb_f[2]);
	if (!cub->rgb_c)
		data.ciel = (cub->rgb_c[0] << 16 | cub->rgb_c[1] << 8 | cub->rgb_c[2]);
	mlx_hook(data.mlx_win, 2, 0, &handle_keypress, &data);
	//calls the user_defined functs when an events occurs
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.mlx_win, 17, 0, fgclose, &data);
	//√will  be  called  when  no  event occurs.
	mlx_loop(data.mlx);
	//It is an infinite loop that waits for an event, and then calls a user-defined function associated with this event
	clean_up(&data);
	return (0);
}
