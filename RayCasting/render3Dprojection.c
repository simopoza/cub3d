/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3Dprojection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:02:31 by mannahri          #+#    #+#             */
/*   Updated: 2023/01/16 19:19:56 by mannahri         ###   ########.fr       */
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
    while (i < info->WINDOW_WIDTH)
    {
        proj.corr_distance = ray[i].distance * cos(ray[i].ray_angle - player.angle);
        proj.distance_proj_plane = (info->WINDOW_WIDTH / 2) / tan(player.view / 2);
        proj.proj_wall_height = (info->SCALE / proj.corr_distance) * proj.distance_proj_plane;
        proj.wall_height = (int)proj.proj_wall_height;
        proj.topPixel = (info->WINDOW_HEIGHT / 2) - (proj.wall_height / 2);
        if (proj.topPixel < 0)
            proj.topPixel = 0;
        proj.bottomPixel = (info->WINDOW_HEIGHT / 2) + (proj.wall_height / 2);
        if (proj.bottomPixel > info->WINDOW_HEIGHT)
            proj.bottomPixel = info->WINDOW_HEIGHT;
        // printf ("topPixel is : %d\nbottomPixel is : %d   __i = %d\n", proj.topPixel, proj.bottomPixel, i);
        printf ("corr : %f\n", proj.corr_distance);
        j = 0;
        while (j < proj.topPixel)
        {
            //should put the ciel color to the window img;
             draw = img.ImgAddr + (j * img.BytesInRow + i * (img.BytesInPx / 8));
             *(int *)draw = 878799;
            j++;
        }
        j = proj.topPixel;
        while (j < proj.bottomPixel)
        {
            //should put a color to the window img;
             draw = img.ImgAddr + (j * img.BytesInRow + i * (img.BytesInPx / 8));
             *(int *)draw = 0xFFFFFF;
            j++;
        }
        j = proj.bottomPixel;
        while (j < info->WINDOW_HEIGHT)
        {
            //should put the floor color to the window img;
             draw = img.ImgAddr + (j * img.BytesInRow + i * (img.BytesInPx / 8));
             *(int *)draw = 134646;
            j++;
        }
        i++;
        
    }
}
