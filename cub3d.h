/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:03:01 by mannahri          #+#    #+#             */
/*   Updated: 2023/01/08 01:20:29 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"
#include "mlx.h"
#include "math.h"

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
	int		map_width;
	int		map_height;
}	t_cub;

typedef struct s_img
{
	void	*MlxImg;
	char	*ImgAddr;
	int		BytesInPx; /* bits per pixel */
	int		BytesInRow;//number of bytes in each row
	int		endian; //??
}	t_img;

typedef struct s_player
{
	float	x_pos;
	float	y_pos;
	int	turn_direction ;
	int	walk_direction ;
	float	walk_speed;
	float	turn_speed;
	float	walk_step;
	float	turn_step;
}t_player;

typedef struct s_infos
{
	void *mlx;
	void *mlx_win;
	t_img img;
	int WINDOW_WIDTH ;
	int WINDOW_HEIGHT;
	char **map;
	t_player player;
}	t_infos;


//get_next_line and some utils
int		ft_strlen_line(char *str);
int		ft_strchr_line(char *str);
char	*ft_strjoin_line(char *s1, char *s2);
char	*ft_substr_line(char *str, int start, int len);
char	*get_next_line(int fd);

//read and check the map
t_cub	*parsing(int ac, char *av[]);
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

// 2D map
int	map_columns(char **map);
int map_rows(char **map);
void	draw_img(t_img *img, int x, int y, int color, int size);
void render_map(t_img *img, char **map);
int	render(t_infos *wnd);
void init_window(t_infos *info);
void print_error(char *msg);
void render_player(t_infos *wnd);
void move(t_infos *info, int flag);
void drawline(t_infos *wnd,float  x0, float y0, float x1, float y1);
#endif