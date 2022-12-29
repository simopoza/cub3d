/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:03:01 by mannahri          #+#    #+#             */
/*   Updated: 2022/12/28 12:01:18 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct cub
{
	char	*line;
	char	*tmp;
	char	*str;
	char	**first_map;
	char	**the_map;
	int		*rgb_f;
	int		*rgb_c;
	char	*no_file;
	char	*so_file;
	char	*we_file;
	char	*ea_file;
}	t_cub;

//get_next_line and some utils
int		ft_strlen_line(char *str);
int		ft_strchr_line(char *str);
char	*ft_strjoin_line(char *s1, char *s2);
char	*ft_substr_line(char *str, int start, int len);
char	*get_next_line(int fd);

//read and check the map
t_cub	*handling_map(char *av[], t_cub *cub);
int		ft_length(char *last, char *cub);
void	check_last_is_cub(char *av[]);
int		end_read(char *str);
void	check_first_map(t_cub *cub);
int		is_it_valid1(char *line, t_cub *cub);
void	ft_exit(void);
void	check_duplicated(t_cub *cub, char *identifier, char *file);
void	check_valid_file(char *line, int i, t_cub *cub, char *identifier);
int		check_char(char c);
void	check_the_map(t_cub *cub);
int		check_player(char c);
int		check_zero(char c);
int		ft_check_last_line(char *line);
int		ft_strlen_double(char **str);
int		mine_strncmp(const char *s1, const char *s2, size_t n, size_t i);
void	check_rgb(char *line, int i, t_cub *cub, char color);

#endif