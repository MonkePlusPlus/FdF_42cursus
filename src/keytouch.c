/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keytouch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:03:58 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/30 14:57:21 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_cmppos(int x, int y, int speed)
{
	if (x > y)
		return (-speed);
	else if (x < y)
		return (speed);
	return (0);
}

int	mouse_movement(int x, int y, t_data *data)
{
	if (data->mouse.left && !data->mouse.right && data->inrendering == 0)
	{
		//ft_printf("left x = %d y = %d\n", x, y);
		data->pos.x += ft_cmppos(data->mouse.vector_x, x, 5);
		data->pos.y += ft_cmppos(data->mouse.vector_y, y, 5);
		data->mouse.vector_x = x;
		data->mouse.vector_y = y;
	}
	else if (data->mouse.right && !data->mouse.left && data->rendering == 0)
	{
		//ft_printf("right x = %d y = %d\n", x, y);
		if (data->mouse.rota_x < x)
			data->axis.alpha += 0.03;
		else if (data->mouse.rota_x > x)
			data->axis.alpha -= 0.03;
		if (data->mouse.rota_y < y)
			data->axis.beta += 0.03;
		else if (data->mouse.rota_y > y)
			data->axis.beta -= 0.03;
		data->mouse.rota_x = x;
		data->mouse.rota_y = y;
	}
	return (0);
}

int	mouse_release(int mousecode, int x, int y, t_data *data)
{
	if (mousecode == 1)
	{
		data->rendering = 0;
		data->mouse.left = 0;
	}
	else if (mousecode == 3)
	{
		data->rendering = 0;
		data->mouse.right = 0;
	}
	return (0);
}

int	mouse_click(int mousecode, int x, int y, t_data *data)
{
	if (mousecode == 1 && data->inrendering == 0)
		data->mouse.left = 1;
	else if (mousecode == 3)
		data->mouse.right = 1;
	else if (mousecode == 4)
		data->zoom += 5;
	else if (mousecode == 5 && data->zoom - 5 > 1)
		data->zoom -= 5;
	else if (mousecode == 5 && data->zoom - 1 > 0)
		data->zoom -= 1;
	return (0);
}

int	key_touch(int keycode, t_data *data)
{
	ft_printf("key : %d\n", keycode);
	if (keycode == 65361)
	{
		data->rendering = 1;
		data->axis.delta -= 0.04;
	}
	else if (keycode == 65363)
	{
		data->rendering = 1;
		data->axis.delta += 0.04;
	}
	else if (keycode == 65307)
		close_window(data);
	else if (keycode == 105)
	{
		data->axis.alpha = 49 * M_PI / 180;
		data->axis.beta = 35.264 * M_PI / 180;
		data->axis.delta = 30.736 * M_PI / 180;
	}
	else if (keycode == 32)
	{
		data->pos.x = 0;
		data->pos.y = 0;
	}
	return (0);
}
