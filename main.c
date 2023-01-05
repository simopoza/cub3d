/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 3022/12/23 16:01:48 by mannahri          #+#    #+#             */
/*   Updated: 2023/01/05 20:25:00 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



int	main(int ac, char *av[])
{
	t_cub	*cub;
	t_window window;

	cub = parsing(ac, av);
	window.cub = cub;
	init_window(&window);
	mlx_loop_hook(window.mlx, &render, &window);
	mlx_loop(window.mlx);
	//mlx_destroy_window(mlx, mlx_win);
	//free(mlx);
	//system("leaks cub3d");
	return (0);
}
