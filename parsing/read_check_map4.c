/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check_map4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:52:28 by mannahri          #+#    #+#             */
/*   Updated: 2023/01/19 20:18:57 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_char(char c)
{
	if (c == '1' || c == '0' || c == ' ' || c == 'N' \
	|| c == 'S' || c == 'E' || c == 'W' || c == '\n')
		return (1);
	else
		return (0);
	return (1);
}

void	ft_back_ground(t_cub *cub, int j, int i)
{
	if (cub->the_map[i][j + 1] == '\0' || j - 1 < 0)
		ft_exit();
	if (j > ft_strlen(cub->the_map[i - 1]) \
	|| j > ft_strlen(cub->the_map[i + 1]))
		ft_exit();
	if (!check_zero(cub->the_map[i - 1][j]) \
	|| !check_zero(cub->the_map[i + 1][j]))
		ft_exit();
	if (cub->the_map[i][j + 1] != '\0')
	{
		if (!check_zero(cub->the_map[i][j - 1]) \
		|| !check_zero(cub->the_map[i][j + 1]))
			ft_exit();
	}
}

void	ft_player(t_cub *cub, int j, int i)
{
	if (j > ft_strlen(cub->the_map[i - 1]) \
	|| j > ft_strlen(cub->the_map[i + 1]))
		ft_exit();
	if (!check_player(cub->the_map[i - 1][j]) \
	|| !check_player(cub->the_map[i + 1][j]))
		ft_exit();
	if (cub->the_map[i][j + 1] == '\0' || j - 1 < 0)
		ft_exit();
	if (!check_player(cub->the_map[i][j + 1]) \
	|| !check_player(cub->the_map[i][j - 1]))
		ft_exit();
}

int	its_just_for_the_norm(t_cub *cub, int j, int i, int player)
{
	if (cub->the_map[i][j] == '0')
		ft_back_ground(cub, j, i);
	if (cub->the_map[i][j] == 'N' || cub->the_map[i][j] == 'E' \
	|| cub->the_map[i][j] == 'S' || cub->the_map[i][j] == 'W')
	{
		if (cub->the_map[i][j] == 'N')
			cub->char_player = 'N';
		if (cub->the_map[i][j] == 'S')
			cub->char_player = 'S';
		if (cub->the_map[i][j] == 'E')
			cub->char_player = 'E';
		if (cub->the_map[i][j] == 'W')
			cub->char_player = 'W';
		cub->player_pos_x = j;
		cub->player_pos_y = i;
		player++;
		ft_player(cub, j, i);
	}
	return (player);
}

void	check_the_map(t_cub *cub)
{
	int	player;
	int	len;
	int	i;
	int	j;

	player = 0;
	len = ft_strlen_double(cub->the_map);
	initial_in_map(cub, len);
	i = 1;
	while (cub->the_map[i] && i != len - 1)
	{
		cub->len_lines[i] = ft_strlen(cub->the_map[i]);
		j = 0;
		while (cub->the_map[i][j])
		{
			if (cub->the_map[i][j] != '\0')
				player = its_just_for_the_norm(cub, j, i, player);
			j++;
		}
		i++;
	}
	cub->len_lines[i] = ft_strlen(cub->the_map[i]);
	cub->rows = i + 1;
	if (player != 1)
		ft_exit();
}