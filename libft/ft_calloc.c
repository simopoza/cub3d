/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:43:59 by mannahri          #+#    #+#             */
/*   Updated: 2021/11/16 01:34:26 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*k;

	k = malloc(count * size);
	if (k == 0)
		return (0);
	ft_bzero(k, count * size);
	return (k);
}

/*int main()
{
	int	i;
	i = 2;
	int c = 3;
	printf("%s",ft_calloc(i, c));
	printf("%s",calloc(i, c));
}*/
/*int main()
{
    printf("%s", ft_calloc(2, 3));
    //printf("%s")
    return(0);
}*/