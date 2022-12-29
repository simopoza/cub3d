/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 08:37:07 by mannahri          #+#    #+#             */
/*   Updated: 2022/07/29 15:02:59 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char	*s, int c)
{
	char	*h;
	int		i;

	h = (char *)s;
	c = (char)c;
	i = 0;
	if (c == 0)
		return (&h[ft_strlen(s)]);
	while (h[i] != '\0')
	{
		if (h[i] == c)
			return (h + i);
		i++;
	}
	return (NULL);
}
/*int main()
{
    char* k = "hamzma";
    char l = 0;
    printf("%s",ft_strchr(k, l));
    printf("%s",strchr(k, l));
    return(0);
}*/
