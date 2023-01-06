/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:51:07 by flouta            #+#    #+#             */
/*   Updated: 2023/01/06 21:29:08 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void drawline(t_infos *wnd, int x0, int y0, int x1, int y1)
{
	float step;
	int dx = x1 - x0;
	int dy = y1 - y0;
	if(abs(dx) > abs(dy))
		step = abs(dx);
	else
		step = abs(dy);
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
	draw_img(&wnd->img, wnd->player.x_pos,  wnd->player.y_pos, 0xFF0000, 3);
	drawline(wnd, wnd->player.x_pos , wnd->player.y_pos ,wnd->player.x_pos + cos(wnd->player.turn_step) * 15  , wnd->player.y_pos + + sin(wnd->player.turn_step) * 15);
}

void move(t_infos *info)
{
	info->player.turn_step  += info->player.turn_direction * info->player.turn_speed;
	info->player.walk_step += info->player.walk_direction * info->player.walk_step;

	info->player.x_pos += cos(info->player.turn_step) * info->player.walk_step;
	info->player.y_pos += sin(info->player.turn_step) * info->player.walk_step;
}