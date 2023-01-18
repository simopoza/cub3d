/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 07:57:01 by mannahri          #+#    #+#             */
/*   Updated: 2023/01/01 07:59:03 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initial_cub(t_cub *cub)
{
	cub->rgb_f = NULL;
	cub->rgb_c = NULL;
	cub->no_file = NULL;
	cub->so_file = NULL;
	cub->we_file = NULL;
	cub->ea_file = NULL;
}

t_cub	*parsing(int ac, char *av[])
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
		exit (1);
	}
	initial_cub(cub);
	cub = handling_map(av, cub);
	printf ("im here u know\nmap is open \n");	
	return (cub);
}