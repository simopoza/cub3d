/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 3022/12/23 16:01:48 by mannahri          #+#    #+#             */
/*   Updated: 2023/01/19 20:06:09 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	get_textures_buffer(t_cub *cub, void *mlx)
{
	char	*texture[4];
	char	*file_name;
	void	*img;
	int		i;

	texture[0] = cub->no_file;
	texture[1] = cub->so_file;
	texture[2] = cub->we_file;
	texture[3] = cub->ea_file;
	i = 0;
	while (i < 4)
	{
		file_name = texture[i];
		img = mlx_xpm_file_to_image(mlx, file_name, 
			&cub->textures[i].width, &cub->textures[i].height);
		if (!img)
		{
			printf ("Error mlx_xpm_file_to_image failed\n");
			exit (1);
		}
		cub->textures[i].add_img = mlx_get_data_addr(img, 
			&cub->textures[i].bits_per_pixel,
			&cub->textures[i].bytes_in_row,
			&cub->textures[i].endian);
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_cub	*cub;
	t_infos	data;

	cub = parsing(ac, av);
	init_start(&data, cub);
	if (cub->rgb_f != NULL)
		data.floor = (cub->rgb_f[0] << 16 | cub->rgb_f[1] << 8 | cub->rgb_f[2]);
	if (cub->rgb_c != NULL)
		data.ciel = (cub->rgb_c[0] << 16 | cub->rgb_c[1] << 8 | cub->rgb_c[2]);
	data.cub = cub;
	mlx_hook(data.mlx_win, 2, 0, &handle_keypress, &data);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.mlx_win, 17, 0, fgclose, &data);
	mlx_loop(data.mlx);
	clean_up(&data);
	return (0);
}
