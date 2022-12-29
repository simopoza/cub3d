/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check_map1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:24:01 by mannahri          #+#    #+#             */
/*   Updated: 2022/12/29 15:27:36 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_it_valid1(char *line, t_cub *cub)
{
	size_t	i;
	char	*str;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == 'F' || line[i] == 'C')
	{
		check_rgb(line, i + 1, cub, line[i]);
		return (1);
	}
	if (!mine_strncmp(line, "NO", 2, i) || !mine_strncmp(line, "SO", 2, i) \
	|| !mine_strncmp(line, "WE", 2, i) || !mine_strncmp(line, "EA", 2, i))
	{
		str = ft_substr(line, i, i + 2);
		check_valid_file(line, i + 2, cub, str);
		free (str);
		return (1);
	}
	return (0);
}

int	ft_length(char *last, char *cub)
{
	int	l_last;
	int	l_cub;

	l_last = ft_strlen(last);
	l_cub = ft_strlen(cub);
	if (l_last > l_cub)
		return (l_last);
	if (l_cub > l_last)
		return (l_cub);
	return (l_cub);
}

void	check_last_is_cub(char *av[])
{
	char	*last;

	last = ft_strrchr(av[1], '.');
	if (last == NULL || ft_strncmp(last, ".cub", ft_length(last, ".cub")))
	{
		printf ("Error no .cub extension\n");
		exit(1);
	}
}

int	end_read(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\n')
		return (0);
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] != ' ')
		return (1);
	return (0);
}
