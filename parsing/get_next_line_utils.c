/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:15:23 by mannahri          #+#    #+#             */
/*   Updated: 2023/01/18 04:09:17 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strlen_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_line(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		l;
	int		k;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	k = 0;
	l = 0;
	str = malloc(sizeof(char) * (i + j + 1));
	if (!str)
		return (NULL);
	while (l < i)
		str[l++] = s1[k++];
	k = 0;
	while (k < j)
		str[l++] = s2[k++];
	str[l] = '\0';
	free(s1);
	return (str);
}

char	*ft_substr_line(char *s, int start, int len)
{
	char	*str;
	char	*ali;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	ali = s;
	i = 0;
	j = 0;
	while (i < len && s[i])
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	while (j < i)
	{
		str[j] = ali[start + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		l;
	int		k;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	k = 0;
	l = 0;
	str = malloc(sizeof(char) * (i + j + 1));
	if (!str)
		return (NULL);
	while (l < i)
		str[l++] = s1[k++];
	k = 0;
	while (k < j)
		str[l++] = s2[k++];
	str[l] = '\0';
	return (str);
}
