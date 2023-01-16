/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:21:34 by flouta            #+#    #+#             */
/*   Updated: 2023/01/16 18:52:53 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void cast_all_rays(t_infos *data)
{
	int i ;
	float ray_angle;
 	i = 0;
	ray_angle = data->player.angle - ( data->player.view * 0.5);
	while(i <data->WINDOW_WIDTH)
	{
		cast_each_ray(data ,ray_angle, i) ;
		ray_angle += data->player.view / data->WINDOW_WIDTH;
		i++;
	}
	// printf("-----------------------------\n");
}

float check_angle(float ray_angle)
{
	ray_angle = remainder(ray_angle, 2 * M_PI);
	if(ray_angle < 0)
		ray_angle += 2 * M_PI;
	return (ray_angle);
}

float distance(float x1, float y1, float x2, float y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void cast_each_ray(t_infos *data , float ray_angle, int ray_index)
{
	int up = 0;
	int down = 0;
	int right = 0;
	int left = 0;

	ray_angle = check_angle(ray_angle);
	// printf("%f\n",ray_angle / (M_PI/180));
	if(ray_angle > 0 && ray_angle < M_PI)
		down = 1;
	up = !down;
	if(ray_angle < M_PI/ 2 || ray_angle >  M_PI * 3/2)
		right = 1;
	left = !right;
	//edge cases
	float first_x = 0;
	float first_y = 0;
	float x_step = 0;
	float y_step = 0;
	// float tan_val = 0;

	//horizontal
		
		first_y = floor(data->player.y_pos / data->SCALE ) * data->SCALE;
		if(down)
			first_y += data->SCALE;
		// tan_val =  floor(100000* tan(ray_angle))/100000;
		// if(tan_val != 0)
			first_x = data->player.x_pos + (first_y - data->player.y_pos) / tan (ray_angle);
		y_step = data->SCALE;
		if(up == 1)
			y_step *= -1;
		// if(tan_val != 0)
			x_step = data->SCALE / tan(ray_angle); //check cases when tan can be a 0 or inf
		 x_step *= (left && x_step > 0) ? -1 : 1;
    	x_step *= (right && x_step < 0) ? -1 : 1;
	
		float h_next_x = first_x;
		float h_next_y = first_y;
		float y_check = first_y;
		while(h_next_x >= 0 && h_next_x <= data->WINDOW_WIDTH&& h_next_y >= 0 && h_next_y <= data->WINDOW_HEIGHT )
		{
			if(up == 1)	
				y_check = h_next_y - 1;
			else
				y_check = h_next_y;
			if(is_wall(data, h_next_x, y_check) == -1)
				break;	
			h_next_x += x_step;
			h_next_y += y_step;
		}
	//vertical

		first_x = floor(data->player.x_pos / data->SCALE ) * data->SCALE;
		if(right)
			first_x += data->SCALE;
		// tan_val =  floor(100000* tan(ray_angle))/100000;
	
		first_y = data->player.y_pos + (first_x - data->player.x_pos) * tan (ray_angle);
		x_step = data->SCALE;
		if(left == 1)
			x_step *= -1;

		y_step = data->SCALE * tan(ray_angle); //check cases when tan can be a 0 or inf
		y_step *= (up && y_step > 0) ? -1 : 1;
    	y_step *= (down&& y_step < 0) ? -1 : 1;
	
		float v_next_x = first_x;
		float v_next_y = first_y;
		float x_check = v_next_x;

		while(v_next_x >= 0 && v_next_x <= data->WINDOW_WIDTH&& v_next_y >= 0 && v_next_y <= data->WINDOW_HEIGHT )
		{
			if(left == 1)	
				x_check = v_next_x - 1;
			else
				x_check = v_next_x;
			if(is_wall(data, x_check, v_next_y) == -1)
				break;
				
			v_next_x += x_step;
			v_next_y += y_step;
		}
		    
		float h_distance = distance(data->player.x_pos, data->player.y_pos, h_next_x, h_next_y);
    	float v_distance = distance(data->player.x_pos, data->player.y_pos, v_next_x, v_next_y);
		if (v_distance < h_distance) {
			// printf("horizental\n");
			data->rays[ray_index].distance = v_distance;
			data->rays[ray_index].wall_x = v_next_x;
			data->rays[ray_index].wall_y = v_next_y;
		} else {
			// printf("vertical\n");
			data->rays[ray_index].distance = h_distance;
			data->rays[ray_index].wall_x =h_next_x;
			data->rays[ray_index].wall_y = h_next_y;
		}
		data->rays[ray_index].ray_angle = ray_angle;

		// printf("%d --> x = %f     y = %f\n",ray_index, data->rays[ray_index].wall_x  , data->rays[ray_index].wall_y);
		

}







