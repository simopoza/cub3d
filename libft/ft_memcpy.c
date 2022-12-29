/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:05:44 by mannahri          #+#    #+#             */
/*   Updated: 2021/11/16 02:30:20 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void	*src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*srrc;
	size_t			i;

	dest = (unsigned char *)dst;
	srrc = (unsigned char *)src;
	i = 0;
	if (dest == srrc)
		return (dest);
	if (dest == NULL && srrc == NULL)
		return (NULL);
	while (i < n)
	{
		dest[i] = srrc[i];
		i++;
	}
	return (dest);
}

// int main()
// {
//     char src[] = "";
//     char dst[] = "";
//     printf("%s", ft_memcpy(dst, src, 1));
//     printf("%s", memcpy(dst, src, 1));
//     return(0);
// }
// int main()
// {
// 	char *src = "abcde";
// 	char ptr[3] = src + 2;
// 	printf("%s", ft_memcpy(src, ptr, 3));
// 	printf("%s", memcpy(src, ptr, 3));
// 	return (0);
// }
/*
int main()
{
    char s[4] = "hello";
    char d[3] = "hi";
    printf("%s\n",ft_memcpy(d,s,3));
    printf("%s",memcpy(d,s,3));
    return 0;
}*/
