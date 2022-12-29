/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 03:15:44 by mannahri          #+#    #+#             */
/*   Updated: 2022/07/29 15:03:56 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*see;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	see = (char *)set;
	if (!see)
		return ((char *)s1);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_check(see, s1[i]))
		i++;
	while (j > 0 && ft_check(see, s1[j]))
		j--;
	return (ft_substr(s1, i, (j - i) + 1));
}
/*int main()
{
	char *k = "iaaaammmsssstahaaaaaaaa";
	char *set = "issam";
	printf("%s",ft_strtrim(k,set));
	return(0);
}*/