/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:02:31 by mannahri          #+#    #+#             */
/*   Updated: 2023/01/19 01:27:55 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    render3Dprojection(t_infos *info)
{
    t_3dproj    proj;
    t_player    player;
    t_ray       *ray;
    t_img       img;
    int         i;
    int         j;
    char        *draw;

    i = 0;
    player = info->player;
    ray = info->rays;
    img = info->img;
    while (i < info->window_width)
    {
        proj.corr_distance = ray[i].distance * cos(ray[i].ray_angle - player.angle);
        if (proj.corr_distance == 0)
            proj.corr_distance = 1;
        proj.distance_proj_plane = (info->window_width / 2) / tan(player.view / 2);
        proj.proj_wall_height = (info->scale / proj.corr_distance) * proj.distance_proj_plane;
        proj.wall_height = (int)proj.proj_wall_height;
        proj.topPixel = (info->window_heigth / 2) - (proj.wall_height / 2);
        if (proj.topPixel < 0)
            proj.topPixel = 0;
        proj.bottomPixel = (info->window_heigth / 2) + (proj.wall_height / 2);
        if (proj.bottomPixel > info->window_heigth)
            proj.bottomPixel = info->window_heigth;
        // printf ("topPixel is : %d\nbottomPixel is : %d   __i = %d\n", proj.topPixel, proj.bottomPixel, i);
        // printf ("corr : %f\n", proj.corr_distance);
        j = 0;
        while (j < proj.topPixel)
        {
            //should put the ciel color to the window img;
             draw = img.img_addr + (j * img.bytes_in_row + i * (img.bytes_in_px / 8));
             *(int *)draw = 878799;
            j++;
        }
        j = proj.topPixel;
        while (j < proj.bottomPixel)
        {
            //should put a color to the window img;
             draw = img.img_addr + (j * img.bytes_in_row + i * (img.bytes_in_px / 8));
             *(int *)draw = 0xFFFFFF;
            j++;
        }
        j = proj.bottomPixel;
        while (j < info->window_heigth)
        {
            //should put the floor color to the window img;
             draw = img.img_addr + (j * img.bytes_in_row + i * (img.bytes_in_px / 8));
             *(int *)draw = 134646;
            j++;
        }
        i++;
        
    }
}
