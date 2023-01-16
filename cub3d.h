/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:03:01 by mannahri          #+#    #+#             */
/*   Updated: 2023/01/16 17:49:23 by mannahri         ###   ########.fr       */
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
	int		player_pos_x;
	int		player_pos_y;
	char	char_player;
}	t_cub;

typedef struct s_img
{
	void	*MlxImg;
	char	*ImgAddr;
	int		BytesInPx; //number of bits needed to represent a pixel color (also called the depth of the image).
	int		BytesInRow;//is the number of bytes used to store one line of the image in memory.
	int		endian; //tells you wether the pixel color in the image needs to be stored in :little (endian == 0), or big (endian == 1).
}	t_img;

typedef struct s_player
{
	float	x_pos;
	float	y_pos;
	int	turn_direction;
	int	walk_direction;
	float	walk_speed;
	float	turn_speed; //bchehl kydor
	float	walk_step;// bchehl kyzid
	float	angle;//fin kychof 
	float	view;//FOV 60
}t_player;

//corrDistance = distance * cos(ray_angle - angle);

typedef struct s_3dproj
{
	int wall_height;
    float distance_proj_plane;
    float proj_wall_height;
    float corr_distance;
    int topPixel;
    int bottomPixel;
}	t_3dproj;

typedef struct s_ray
{
	float ray_angle;//ray angle ta3o
	float wall_x;
	float wall_y;
	float distance;//ray.distance
	//is vertical or horizantal
	//is up down left right
	//int wall hit content 
} t_ray;

typedef struct s_infos
{
	void *mlx;
	void *mlx_win;
	t_img img;
	int WINDOW_WIDTH;
	int WINDOW_HEIGHT;
	int SCALE;
	char **map;
	t_player player;
	t_ray *rays;
	int		floor;
	int		ciel;
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
void render_map(t_infos *data);
int	render(t_infos *wnd);
void init_window(t_infos *info, t_cub *cub);
void print_error(char *msg);
//player
void render_player(t_infos *wnd);
void move(t_infos *info, int flag);
void drawline(t_infos *wnd,float  x0, float y0, float x1, float y1);
//player moves
int	handle_keypress(int keysym, t_infos *data);
int	handle_keyrelease(int keysym, t_infos *data);
//wall collision
int is_wall(t_infos *wnd,float x, float y);
//rays
void cast_all_rays(t_infos *data);
void cast_each_ray(t_infos *data , float ray_angle, int ray_index);
float check_angle(float ray_angle);
void castRay(t_infos *data, float rayAngle, int stripId) ;
float distance(float x1, float y1, float x2, float y2);
//3D projection
void    render3Dprojection(t_infos *info);


#endif