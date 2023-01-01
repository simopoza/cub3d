/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check_map0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 00:02:18 by mannahri          #+#    #+#             */
/*   Updated: 2023/01/01 08:01:25 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	*check_rgb_range_nums(char **numbers)
{
	int	*rgb;
	int	i;
	int	k;

	rgb = malloc (sizeof (int) * 3);
	i = 0;
	while (numbers[i])
	{
		rgb[i] = ft_atoi(numbers[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
		{
			printf ("Error in the map out of range\n");
			exit (1);
		}
		i++;
	}
	k = 0;
	while (numbers[k])
		free (numbers[k++]);
	free (numbers);
	return (rgb);
}

void	check_numbers(char *line, char *sub)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (sub[i])
	{
		if (sub[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
	{
		printf ("Error in the map\n");
		exit (1);
	}
	if (line[ft_strlen(line) - 1] == ',')
	{
		printf ("Error in the map\n");
		exit (1);
	}
}

void	check_errors(char color, int j, t_cub *cub, char **numbers)
{
	if (j != 3)
	{
		printf ("Error in the map num of rgb\n");
		exit (1);
	}
	if (color == 'F')
	{
		if (cub->rgb_f != NULL)
		{
			printf ("Error in the map color2\n");
			exit (1);
		}
		cub->rgb_f = check_rgb_range_nums(numbers);
	}
	if (color == 'C')
	{
		if (cub->rgb_c != NULL)
		{
			printf ("Error in the map color1\n");
			exit (1);
		}
		cub->rgb_c = check_rgb_range_nums(numbers);
	}
}

void	check_rgb(char *line, int i, t_cub *cub, char color)
{
	char	**numbers;
	char	*sub;
	int		j;
	int		l;

	j = 0;
	while (line[i] && line[i] == ' ')
		i++;
	sub = ft_substr(line, i, ft_strlen(line));
	numbers = ft_split(sub, ',');
	check_numbers(line, sub);
	free (sub);
	while (numbers[j])
	{
		l = 0;
		while (numbers[j][l])
		{
			if (!(numbers[j][l] >= 48 && numbers[j][l] <= 57))
				ft_exit();
			l++;
		}
		j++;
	}
	check_errors(color, j, cub, numbers);
}

int	mine_strncmp(const char *s1, const char *s2, size_t n, size_t i)
{
	size_t	j;

	j = 0;
	if (n == 0)
		return (0);
	if (!s1 || !s2)
		return (-1);
	while (s1[i] == s2[j] && s1[i] && s2[j] && j < n - 1)
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
