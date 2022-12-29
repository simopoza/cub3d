/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:15:43 by mannahri          #+#    #+#             */
/*   Updated: 2022/09/15 18:15:28 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char	*s)
{
	char	*l;
	int		i;

	if (!s)
		return (0);
	l = (char *)s;
	i = 0;
	while (l[i])
		i++;
	return (i);
}
/*int main()
{
    char* l = "lkjh";
    printf("%zu",ft_strlen(l));
    return(0);
}*/
