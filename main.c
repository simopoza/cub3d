/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:01:48 by mannahri          #+#    #+#             */
/*   Updated: 2022/12/29 15:31:41 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initial_cub(t_cub *cub)
{
	cub->rgb_f = NULL;
	cub->rgb_c = NULL;
	cub->no_file = NULL;
	cub->so_file = NULL;
	cub->we_file = NULL;
	cub->ea_file = NULL;
}

int	main(int ac, char *av[])
{
	t_cub	*cub;

	if (ac != 2)
	{
		printf ("Error wrong num of arguments.\n");
		exit(1);
	}
	check_last_is_cub(av);
	cub = malloc(sizeof (t_cub));
	if (!cub)
	{
		printf ("Error allocation\n");
		return (-1);
	}
	initial_cub(cub);
	cub = handling_map(av, cub);
	printf ("im here u know\nmap is open \n");
	while (1);
	return (0);
}
