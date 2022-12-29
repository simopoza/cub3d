/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:33:56 by mannahri          #+#    #+#             */
/*   Updated: 2021/11/17 22:45:29 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <fcntl.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*int main()
{
    int fd;
    fd = open("file.txt",O_WRONLY);
    ft_putchar_fd('k', fd);
}*/

/*int main()
{
	char c = 'l';
	int fd = 5;
	ft_putchar_fd(c,fd);
	return (0);
}*/