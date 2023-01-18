/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 3022/12/23 16:01:48 by mannahri          #+#    #+#             */
/*   Updated: 2023/01/18 17:22:05 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_color(int R, int G, int B)
{
	return (R << 16 | G << 8 | B);
}

int	main(int ac, char *av[])
{
	t_cub	*cub;
	t_infos	data;

	cub = parsing(ac, av);
	init_window(&data, cub);
	if (cub->rgb_f != NULL)
		data.floor = (cub->rgb_f[0] << 16 | cub->rgb_f[1] << 8 | cub->rgb_f[2]);
	if (cub->rgb_c != NULL)
		data.ciel = (cub->rgb_c[0] << 16 | cub->rgb_c[1] << 8 | cub->rgb_c[2]);
	data.cub = cub;
	mlx_hook(data.mlx_win, 2, 0, &handle_keypress, &data);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_loop(data.mlx);
	while(1);
	mlx_destroy_window(data.mlx, data.mlx_win);
	free(data.mlx);
	return (0);
}
