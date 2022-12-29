/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:35:16 by mannahri          #+#    #+#             */
/*   Updated: 2021/11/15 17:21:15 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*a;
	char	*b;

	a = (char *)dst;
	b = (char *)src;
	if (a > b)
	{
		while (len--)
		{
			a[len] = b[len];
		}
		return (a);
	}
	return (ft_memcpy(a, b, len));
}

/*int main()
{
	char src[] = "abcde";
	char *dst = src + 2;
	// char *ptr = src + 2;
	// char dst[5];

	//printf("%s\n", ft_memmove(dst, src, 3));
	printf("%s", memmove(src + 2, src, 3));
	return (0);
}*/
/*int main()
{
    char src[] = "abcdefgh";
	char *dst = src + 2;
    //memcpy(s1 + 2, s1, 5);
    printf("theirs %s \n", memcpy(dst, src, 5));
    //ft_memmove(s1 + 2, s1, 5);
    //printf("mmine %s \n", ft_memmove(dst, src, 5));
}*/
/*int main()
{
    char src[] = "future is loading";
    char dst[] = "aaaaaaaaaaaaaaaaa";
    printf("%s\n", ft_memmove(dst, src, 5));
    printf("%s\n", memmove(dst, src, 5));
    return(0);
}
int main()
{
    char d[] = "yassine";
    char s[] = "dahni";
    memmove(s,s+2,5);
    printf("%s",s);
}*/
