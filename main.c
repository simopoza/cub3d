/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:01:48 by mannahri          #+#    #+#             */
/*   Updated: 2023/01/01 08:14:52 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char *av[])
{
	t_cub	*cub;
	
	cub = parsing(ac, av);
	while (1);
	return (0);
}

//PI we can change PI to degree
//and we know that : WE = PI = 180deg | NO = 3PI/2 = 260 | SO = 2PI:0 = 0 | EA = PI/2 = 90