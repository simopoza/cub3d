/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:50:03 by mannahri          #+#    #+#             */
/*   Updated: 2022/12/25 00:59:20 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr_split(const char *s, int start, int len)
{
	char	*str;
	char	*ali;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	ali = (char *)s;
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

int	ft_count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

char	**ft_putsplit(char **arr, char const *s, char c)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		len = i;
		while (s[len] && s[len] != c)
			len++;
		if (s[i] && s[i] != c)
		{
			arr[j] = ft_substr_split(s, i, len - i);
			j++;
		}
		i = len;
	}
	arr[j] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	return (ft_putsplit(arr, s, c));
}
