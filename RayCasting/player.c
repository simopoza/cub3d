/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:51:07 by flouta            #+#    #+#             */
/*   Updated: 2023/01/12 02:03:09 by flouta           ###   ########.fr       */
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
	draw_img(&wnd->img, wnd->player.x_pos,  wnd->player.y_pos, 0xFF0000, 2);
	drawline(wnd, wnd->player.x_pos , wnd->player.y_pos ,wnd->player.x_pos + cos(wnd->player.angle) * 30 , wnd->player.y_pos  + sin(wnd->player.angle) * 30);
}

int is_wall(t_infos *wnd,float x, float y)
{
	if(x < 0 || x > wnd->WINDOW_WIDTH || y < 0 || y > wnd->WINDOW_HEIGHT)
	{

		return -1;
	}
		
	if(wnd->map[(int)floor(y / wnd->SCALE)][(int)floor(x / wnd->SCALE)] == '1')
		return -1;
	return 1;
		
}
void move(t_infos *info, int flag)
{
	float new_x;
	float new_y;

	info->player.walk_step = info->player.walk_direction * info->player.walk_speed;
	info->player.angle += info->player.turn_direction * info->player.turn_speed ;
	if(flag == 1)
	{
		new_x = info->player.x_pos + cos(info->player.angle + M_PI/2) * info->player.walk_step;
		new_y = info->player.y_pos + sin(info->player.angle + M_PI/2) * info->player.walk_step;

	}else
	{
		new_x = info->player.x_pos + cos(info->player.angle) * info->player.walk_step;
		new_y = info->player.y_pos + sin(info->player.angle) * info->player.walk_step;
	}
	if(is_wall(info, new_x, new_y) == 1)
	{
		info->player.x_pos = new_x;
		info->player.y_pos = new_y;
	}
}

int	handle_keypress(int keysym, t_infos *data)
{
	int flag;

	flag = 0;
	data->player.walk_direction = 0;
	data->player.turn_direction = 0;
	if(keysym == 13)
		data->player.walk_direction = 1;
	if(keysym == 1)
		data->player.walk_direction = -1;
	if(keysym == 123)
		data->player.turn_direction = -1;
	if(keysym == 124)
		data->player.turn_direction = 1;
	if(keysym == 2)
	{
		data->player.walk_direction = 1;
		flag = 1;
	}
	if(keysym == 0)
	{
		data->player.walk_direction = -1;
		flag = 1;
	}
	move(data,flag);
	cast_all_rays(data);
	return (0);
}

// int	handle_keyrelease(int keysym, t_infos *data)
// {
// 	if(keysym == 13)
// 		data->player.walk_direction = 0;
// 	if(keysym == 1)
// 		data->player.walk_direction = 0;
// 	if(keysym == 123)
// 		data->player.turn_direction = 0;
// 	if(keysym == 124)
// 		data->player.turn_direction = 0;
// 	if(keysym == 2)
// 	{
// 		data->player.walk_direction = 0;
// 	}
// 	if(keysym == 0)
// 	{
// 		data->player.walk_direction = 0;
// 	}
// 	return (0);
// }