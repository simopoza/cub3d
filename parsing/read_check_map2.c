/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check_map2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:25:25 by mannahri          #+#    #+#             */
/*   Updated: 2023/01/19 20:01:37 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initial_in_map(t_cub *cub, int len)
{
	cub->len_lines = malloc(sizeof(int) * len);
	if (ft_check_last_line(cub->the_map[len - 1]))
		ft_exit();
	cub->len_lines[0] = ft_strlen(cub->the_map[0]);
}

void	ft_exit(void)
{
	printf ("Error in the map\n");
	exit (1);
}

int	check_duplicated_norm(t_cub *cub, char *identifier, char *file, int flag)
{
	if (!ft_strncmp(identifier, "NO", 2))
	{
		if (cub->no_file != NULL)
			flag = 1;
		cub->no_file = file;
	}
	if (!ft_strncmp(identifier, "SO", 2))
	{
		if (cub->so_file != NULL)
			flag = 1;
		cub->so_file = file;
	}
	if (!ft_strncmp(identifier, "WE", 2))
	{
		if (cub->we_file != NULL)
			flag = 1;
		cub->we_file = file;
	}
	if (!ft_strncmp(identifier, "EA", 2))
	{
		if (cub->ea_file != NULL)
			flag = 1;
		cub->ea_file = file;
	}
	return (flag);
}

void	check_duplicated(t_cub *cub, char *identifier, char *file)
{
	int	flag;

	flag = 0;
	flag = check_duplicated_norm(cub, identifier, file, flag);
	if (flag == 1)
	{
		printf ("Error in the map Duplication\n");
		exit (1);
	}
}

void	check_valid_file(char *line, int i, t_cub *cub, char *identifier)
{
	int		fd;
	char	*file;

	while (line[i] && line[i] == ' ')
		i++;
	file = ft_substr(line, i, ft_strlen(line));
	if (!file[0])
	{
		printf ("Error in the map file\n");
		exit (1);
	}
	fd = open(file, O_RDONLY, 0664);
	if (fd < 0)
	{
		printf ("Error in u know file.,.,.\n");
		exit (1);
	}
	check_duplicated(cub, identifier, file);
}