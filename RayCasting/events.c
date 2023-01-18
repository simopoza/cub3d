#include "../cub3d.h"

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