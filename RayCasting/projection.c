/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:02:31 by mannahri          #+#    #+#             */
/*   Updated: 2023/01/19 20:46:41 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	rend.proj.corr_distance = rend.ray[rend.i].distance * cos(rend.ray[rend.i].ray_angle - rend.player.angle);
    if (rend.proj.corr_distance == 0)
        rend.proj.corr_distance = 1;
	rend.proj.distance_proj_plane = (info->window_width / 2) / tan(rend.player.view / 2);
	rend.proj.proj_wall_height = (info->scale / rend.proj.corr_distance) * rend.proj.distance_proj_plane;
	rend.proj.wall_height = (int)rend.proj.proj_wall_height;
	rend.proj.top_pixel = (info->window_heigth / 2) - (rend.proj.wall_height / 2);
	if (rend.proj.top_pixel < 0)
		rend.proj.top_pixel = 0;
	rend.proj.bottom_pixel = (info->window_heigth / 2) + (rend.proj.wall_height / 2);
	if (rend.proj.bottom_pixel > info->window_heigth)
		rend.proj.bottom_pixel = info->window_heigth;
	return (rend.proj);
}

void	projection_ciel(t_rend rend, t_infos *info)
{
	rend.j = 0;
	while (rend.j < rend.proj.top_pixel)
	{
		rend.draw = rend.img.img_addr + \
		(rend.j * rend.img.bytes_in_row + rend.i * (rend.img.bytes_in_px / 8));
		*(unsigned int *)rend.draw = info->ciel;
		rend.j++;
	}
}


int	calculate_which_texture_index(t_rend rend, t_infos *info)
{
	int	index;
	if (info->rays[rend.i].direction == vertical)
	{
		if(info->rays[rend.i].right_left == left)
			index = 0;
		else
			index = 1;
	}
	else
	{
		if (info->rays[rend.i].up_down == up)
			index = 2;
		else
			index = 3;
	}
	return (index);
}

void	projection_wall(t_rend rend, t_infos *info)
{
	int i;
	int ofx;
	int ofy;
	int distance;
    char *pixal;

    i = calculate_which_texture_index(rend, info);
	if (rend.ray[rend.i].direction == vertical)
    {
       	ofx = rend.ray[rend.i].wall_y * info->cub->textures[i].width / info->scale;
		ofx %= info->cub->textures[i].width;
    }
	else
    {
        ofx = rend.ray[rend.i].wall_x * info->cub->textures[i].width / info->scale;
		ofx %=  info->cub->textures[i].width;
    }
	rend.j = rend.proj.top_pixel;
	while (rend.j < rend.proj.bottom_pixel)
	{
		// distance = rend.j - rend.proj.top_pixel;
		distance = rend.j - (info->window_heigth / 2) + (rend.proj.wall_height / 2);
		ofy = (int)(distance * ((float)(info->cub->textures[i].height) / rend.proj.wall_height));
        pixal = info->cub->textures[i].add_img + (ofy * info->cub->textures[i].bytes_in_row) + ofx * (info->cub->textures[i].bits_per_pixel / 8);
		rend.draw = rend.img.img_addr + (rend.j * rend.img.bytes_in_row + rend.i * (rend.img.bytes_in_px / 8));
		*(unsigned int *)rend.draw = *(unsigned int *)pixal;
		// *(unsigned int *)rend.draw = 88888;
		rend.j++;
	}
}

void	projection_floor(t_rend rend, t_infos *info)
{
	rend.j = rend.proj.bottom_pixel;
	while (rend.j < info->window_heigth)
	{
		rend.draw = rend.img.img_addr + \
		(rend.j * rend.img.bytes_in_row + rend.i * (rend.img.bytes_in_px / 8));
		*(unsigned int *)rend.draw = info->floor;
		rend.j++;
	}
}

void	render3Dprojection(t_infos *info)
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
//     t_ray       *ray[rend.i].//     t_img       img;
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
