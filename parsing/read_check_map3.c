/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check_map3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:51:28 by mannahri          #+#    #+#             */
/*   Updated: 2023/01/19 18:56:49 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_first_map(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->first_map[i])
	{
		if (!is_it_valid1(cub->first_map[i], cub))
		{
			printf ("Error in the map\n");
			exit (1);
		}
		i++;
	}
}

int	ft_strlen_double(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_check_last_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] == ' ' || line[i] == '1'))
			return (1);
		i++;
	}
	return (0);
}

int	check_zero(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '1' || c == '0')
		return (1);
	return (0);
}

int	check_player(char c)
{
	if (c == '1' || c == '0')
		return (1);
	return (0);
}
