/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:31:48 by mannahri          #+#    #+#             */
/*   Updated: 2022/09/15 01:27:34 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	char	*str1;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	str1 = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str1)
		return (NULL);
	while (s1[i])
	{
		str1[i] = s1[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}
/*int main()
{
	char *k = 0;
	printf("%s\n",strdup(NULL));
	return (0);
}*/