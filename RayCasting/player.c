/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:51:07 by flouta            #+#    #+#             */
/*   Updated: 2023/01/19 00:18:24 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void drawline(t_infos *wnd, float x0, float y0, float x1, float y1)//change it
{
	float step;
	t_cord cord;
	float dx ;
	float dy ;

	cord.size = 1;
	dx = x1 - x0;
	dy =  y1 - y0;
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
		cord.x = x0;
		cord.y = y0;
		draw_img(wnd, &cord, 0xFF0000);
		x0 += xinc;
		y0 += yinc;
	}
}

// void render_player(t_infos *wnd)
// {
// 	draw_img(&wnd->img, wnd->player.x_pos,  wnd->player.y_pos, 0xFF0000, 2);
// 	//drawline(wnd, wnd->player.x_pos , wnd->player.y_pos ,wnd->player.x_pos + cos(wnd->player.angle) * 30 , wnd->player.y_pos  + sin(wnd->player.angle) * 30);
// }

int is_wall(t_infos *wnd,float x, float y) // fix is wall
{
	if(x < 0 || x > wnd->WINDOW_WIDTH || y < 0 || y > wnd->WINDOW_HEIGHT)
	{

		return -1;
	}
	int x_check = floor(y / wnd->SCALE);
	int y_check = floor(x / wnd->SCALE);
	int i = 0;
	if(x_check < wnd->rows)
	{
		while(wnd->map[x_check][i])
			i++;
	}
	if(x_check < wnd->rows && y_check < wnd->row_len[x_check] &&  wnd->map[x_check][y_check] == '1')
		return -1;
	return 1;
		
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