/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:35:14 by mannahri          #+#    #+#             */
/*   Updated: 2022/09/15 21:54:16 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen1(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		l;
	int		k;

	i = ft_strlen1(s1);
	j = ft_strlen1(s2);
	k = 0;
	l = 0;
	str = malloc(sizeof(char) * (i + j + 1));
	if (!str)
		return (NULL);
	while (l < i)
		str[l++] = s1[k++];
	k = 0;
	while (k < j)
		str[l++] = s2[k++];
	str[l] = '\0';
	free(s1);
	free (s2);
	return (str);
}

// char	*ft_strjoin(char const	*s1, char const	*s2)
// {
// 	int		i;
// 	int		j;
// 	char	*str;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	i = ft_strlen(s1) + ft_strlen(s2);
// 	str = malloc(sizeof(char) * (i + 1));
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i])
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2[j])
// 	{
// 		str[i] = s2[j];
// 		j++;
// 		i++;
// 	}
// 	str[i] = '\0';
// 	free ((void*)s1);
// 	return (str);
// }
/*int	main()
{
	char s1[] = "tahaha";
	char s2 [] = "**";
	char *s3 = ft_strjoin(s1,s2);
	printf("%s",s3); 
}
*/
/*int main()
{
	char k[] = "ljfkh";
	char t[] = "lllll";
	printf("%s", ft_strjoin(k, t));
	return(0);
}*/