/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:57:41 by mannahri          #+#    #+#             */
/*   Updated: 2021/11/16 01:46:36 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*h;
	size_t			i;

	h = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (h[i] == (unsigned char)c)
			return (&h[i]);
		i++;
	}
	return (NULL);
}
/*int main()
{
    char* k = "humama";
    char l = 'm';
    printf("%s\n",ft_memchr(k, l,3));
    printf("%s",memchr(k, l, 3));
    return(0);
}
*/