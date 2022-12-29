/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:20:13 by mannahri          #+#    #+#             */
/*   Updated: 2022/07/29 15:03:12 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dst, const char	*src, size_t dstsize)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen(src);
	if (dst == src)
		return (l);
	if (dst == NULL && src == NULL)
		return (0);
	if (dstsize == 0)
		return (l);
	while (src[i] && (i < dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (l);
}

/*int main()
{
    char* dest = "idyahya";
    char* srrc = "yogyo4444444";
    //printf("%zu\n",ft_strlcpy(dest, srrc,3));
    
    printf("%zu",strlcpy(dest, srrc,3));
    return(0);
}*/
