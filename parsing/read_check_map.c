/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:15:01 by mannahri          #+#    #+#             */
/*   Updated: 2023/01/05 18:29:27 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	first_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
		{
			printf ("Error\n");
			exit (1);
		}
		i++;
	}
	return (1);
}

void	check_outside_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!check_char(str[i]))
		{
			printf ("ERROR IN THE MAP\n");
			exit (1);
		}
		i++;
	}
}

void	read_second_map(t_cub *cub, int fd)
{
	static int	flag;

	if (cub->str[0] == '\n')
	{
		printf ("Error\n");
		exit (1);
	}
	check_outside_char(cub->str);
	cub->tmp = ft_strjoin_line(cub->tmp, cub->str);
	if (flag != 1)
	{
		if (first_line(cub->str))
			flag = 1;
	}
	free (cub->str);
	cub->str = get_next_line(fd);
}

void	read_map(t_cub *cub, int fd)
{
	int	count;

	count = 0;
	cub->tmp = NULL;
	cub->line = NULL;
	cub->str = get_next_line(fd);
	while (cub->str != NULL)
	{
		if (count <= 6)
		{
			cub->line = ft_strjoin_line(cub->line, cub->str);
			free (cub->str);
			cub->str = get_next_line(fd);
		}
		else
			read_second_map(cub, fd);
		if (!cub->str)
			break ;
		if (count <= 6)
			if (end_read(cub->str))
				count++;
	}
}

t_cub	*handling_map(char *av[], t_cub *cub)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error file does not exists\n");
		exit(1);
	}
	read_map(cub, fd);
	cub->first_map = ft_split(cub->line, '\n');
	cub->the_map = ft_split(cub->tmp, '\n');
	check_first_map(cub);
	if (cub->tmp != NULL)
		check_the_map(cub);
	return (cub);
}
