/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:02:31 by mannahri          #+#    #+#             */
/*   Updated: 2023/01/18 18:17:14 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// unsigned int my_mlx_pixel_put(t_data *data, int x, int y)
// {
// 	int	**dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	return *dst;
// }

t_rend	initial_rend(t_infos *info)
{
	t_rend	rend;

	rend.i = 0;
	rend.player = info->player;
	rend.ray = info->rays;
	rend.img = info->img;
	return (rend);
}

t_3dproj	calculate_wall_heigth(t_rend rend, t_infos *info)
{
	rend.proj.corr_distance = rend.ray[rend.i].distance \
	* cos(rend.ray[rend.i].ray_angle - rend.player.angle);
    if (rend.proj.corr_distance == 0)
        rend.proj.corr_distance = 1;
	rend.proj.distance_proj_plane = (info->window_width / 2) \
	/ tan(rend.player.view / 2);
	rend.proj.proj_wall_height = (info->scale / rend.proj.corr_distance) \
	* rend.proj.distance_proj_plane;
	rend.proj.wall_height = (int)rend.proj.proj_wall_height;
	rend.proj.top_pixel = (info->window_height / 2) \
	- (rend.proj.wall_height / 2);
	if (rend.proj.top_pixel < 0)
		rend.proj.top_pixel = 0;
	rend.proj.bottom_pixel = (info->window_height / 2) \
	+ (rend.proj.wall_height / 2);
	if (rend.proj.bottom_pixel > info->window_height)
		rend.proj.bottom_pixel = info->window_height;
	return (rend.proj);
}

void	projection_ciel(t_rend rend, t_infos *info)
{
	rend.j = 0;
	while (rend.j < rend.proj.top_pixel)
	{
		rend.draw = rend.img.img_addr + \
		(rend.j * rend.img.bytes_in_row + rend.i * (rend.img.bytes_in_px / 8));
		*(int *)rend.draw = info->ciel;
		rend.j++;
	}
}

void	projection_wall(t_rend rend, t_infos *info)
{
	(void)info;
	rend.j = rend.proj.top_pixel;
	while (rend.j < rend.proj.bottom_pixel)
	{
		rend.draw = rend.img.img_addr + \
		(rend.j * rend.img.bytes_in_row + rend.i * (rend.img.bytes_in_px / 8));
		*(int *)rend.draw = 0xFFFFFF;
		rend.j++;
	}
}

void	projection_floor(t_rend rend, t_infos *info)
{
	rend.j = rend.proj.bottom_pixel;
	while (rend.j < info->window_height)
	{
		rend.draw = rend.img.img_addr + \
		(rend.j * rend.img.bytes_in_row + rend.i * (rend.img.bytes_in_px / 8));
		*(int *)rend.draw = info->floor;
		rend.j++;
	}
}

void	render3dprojection(t_infos *info)
{
	t_rend		rend;
	rend = initial_rend(info);
	while (rend.i < info->window_width)
	{
		rend.proj = calculate_wall_heigth(rend, info);
		projection_ciel(rend, info);
		projection_wall(rend, info);
		projection_floor(rend, info);
		rend.i++;
	}
}

// void    render3dprojection(t_infos *info)
// {
//     t_3dproj    proj;
//     t_player    player;
//     t_ray       *ray;
//     t_img       img;
//     int         i;
//     int         j;
//     char        *draw;

//     i = 0;
//     player = info->player;
//     ray = info->rays;
//     img = info->img;
//     while (i < info->window_width)
//     {
//         proj.corr_distance = ray[i].distance * cos(ray[i].ray_angle - player.angle);
//         if (proj.corr_distance == 0)
//             proj.corr_distance = 1;
//         proj.distance_proj_plane = (info->window_width / 2) / tan(player.view / 2);
//         proj.proj_wall_height = (info->scale / proj.corr_distance) * proj.distance_proj_plane;
//         proj.wall_height = (int)proj.proj_wall_height;
//         proj.top_pixel = (info->window_height / 2) - (proj.wall_height / 2);
//         if (proj.top_pixel <= 0)
//             proj.top_pixel = 0;
//         proj.bottom_pixel = (info->window_height / 2) + (proj.wall_height / 2);
//         if (proj.bottom_pixel >= info->window_height)
//             proj.bottom_pixel = info->window_height;
//         j = 0;
//         while (j < proj.top_pixel)
//         {
//                 draw = img.img_addr + (j * img.bytes_in_row + i * (img.bytes_in_px / 8));
//                 *(unsigned int *)draw = 878799;//seg
//             j++;
//         }
// 		j = proj.top_pixel;
//         while (j < proj.bottom_pixel)
//         {
//             draw = img.img_addr + (j * img.bytes_in_row + i * (img.bytes_in_px / 8));
//             *(unsigned int *)draw = 0xFFFFFF;
//             j++;
//         }
//         while (j < info->window_height)
//         {
//             draw = img.img_addr + (j * img.bytes_in_row + i * (img.bytes_in_px / 8));
// 			*(unsigned int *)draw = 134646;
// 			j++;
//         }
//         i++;
//     }
// }
