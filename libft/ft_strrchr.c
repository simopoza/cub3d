/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:43:50 by mannahri          #+#    #+#             */
/*   Updated: 2021/11/17 22:48:37 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char	*s, int c)
{
	char	*x;
	int		l;

	x = (char *)s;
	if (c == 0)
		return (x + ft_strlen(x));
	l = ft_strlen(x);
	while (l >= 0)
	{
		if (x[l] == c)
			return (&x[l]);
		l--;
	}
	return (0);
}
// int main()
// {
// 	const char* str2 = "hamama";
// 	int *p;

// 	printf ("%d\n", sizeof(p));
//     char c = 0;
//     printf("%s\n",ft_strrchr(l, c));
//     printf("%s", ft_strrchr(str2 + 2, 0));
//     //printf("%s",strrchr(str2 + 2,  0));
//     return(0);
// }
