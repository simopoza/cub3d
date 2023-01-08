/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:51:07 by flouta            #+#    #+#             */
/*   Updated: 2023/01/08 01:32:00 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void drawline(t_infos *wnd, float x0, float y0, float x1, float y1)
{
	float step;
	float dx = x1 - x0;
	float dy = y1 - y0;
	if(fabs(dx) > fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	float xinc;
	float yinc;
	xinc = dx/step;
	yinc = dy/step;

	for(int i = 0; i < step ;i++)
	{
		draw_img(&wnd->img, x0, y0, 0xFF0000, 1);
		x0 += xinc;
		y0 += yinc;
	}
}

void render_player(t_infos *wnd)
{
	draw_img(&wnd->img, wnd->player.x_pos,  wnd->player.y_pos, 0xFF0000, 5);
	drawline(wnd, wnd->player.x_pos , wnd->player.y_pos ,wnd->player.x_pos + cos(wnd->player.turn_step) * 60  , wnd->player.y_pos  + sin(wnd->player.turn_step) * 60);
}

// int is_wall(t_infos *wnd,float x, float y)
// {
// 	if(x < 0 || x > wnd->WINDOW_WIDTH || y < 0 || y > wnd->WINDOW_HEIGHT)
// 		return -1;
// 	if(wnd->map[(int)floor(x/60)][(int)floor(y/60)] == '1')
		
// }
void move(t_infos *info, int flag)
{
	info->player.walk_step = info->player.walk_direction * info->player.walk_speed;
	info->player.turn_step += info->player.turn_direction * info->player.turn_speed ;
	if(flag == 1)
	{
		info->player.x_pos += cos(info->player.turn_step + M_PI/2) * info->player.walk_step;
		info->player.y_pos += sin(info->player.turn_step + M_PI/2) * info->player.walk_step;
	}else
	{
		info->player.x_pos += cos(info->player.turn_step) * info->player.walk_step;
		info->player.y_pos += sin(info->player.turn_step) * info->player.walk_step;
	}		

}