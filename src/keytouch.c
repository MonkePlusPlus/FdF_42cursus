/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keytouch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:03:58 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/14 17:58:11 by ptheo            ###   ########.fr       */
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
	else
		return (key_touch2(keycode, data));
	return (0);
}

int	key_touch2(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(data);
	else if (keycode == 112)
	{
		data->axis.alpha = 0;
		data->axis.beta = 0;
		data->axis.delta = 0;
	}
	else if (keycode == 114 || keycode == 103
		|| keycode == 98 || keycode == 119)
	{
		data->change_color = 1;
		if (keycode == 114)
			data->color = RED;
		else if (keycode == 103)
			data->color = GREEN;
		else if (keycode == 98)
			data->color = BLUE;
		else if (keycode == 119)
			data->color = WHITE;
	}
	else
		key_touch_utils(keycode, data);
	return (0);
}
