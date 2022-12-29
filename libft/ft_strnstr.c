/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:44:47 by mannahri          #+#    #+#             */
/*   Updated: 2021/11/16 03:02:00 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay;
	char	*nee;
	size_t	i;
	size_t	j;

	hay = (char *)haystack;
	nee = (char *)needle;
	i = 0;
	if (nee[0] == '\0')
		return (hay);
	while (hay[i] && i < len)
	{
		j = 0;
		while (hay[i + j] && hay[i + j] == nee[j] && (j + i) < len)
		{
			if (nee[j + 1] == '\0')
				return (&hay[i]);
			j++;
		}
		i++;
	}
	return (0);
}
// int main()
// {
//     char* k = "Thas is our school";
//     char* l = "is";
//     printf("%s\n",ft_strnstr(k, l, 10));
//     // printf("%s", strnstr(k, NULL, 0));
//     return(0);
// }
