/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:34:01 by mannahri          #+#    #+#             */
/*   Updated: 2021/11/16 02:23:21 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src;
	unsigned char	*dest;
	size_t			i;

	src = (unsigned char *)s1;
	dest = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (src[i] == dest[i] && i < n - 1)
		i++;
	return (src[i] - dest[i]);
}

// int main()
// {
// 	char k[] = "aaŽed";
// 	char l[] = "aaaub";
// 	printf("%d", ft_memcmp(k,l,3));
// 	printf("\n%d", memcmp(k,l,3));
// }