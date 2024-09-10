/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 01:05:47 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/10 19:40:08 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	roll(t_axe axis, t_pos *pos)
{
	double	n_y;
	double	n_z;

	n_y = pos->b * cos(axis.alpha) + pos->c * -sin(axis.alpha);
	n_z = pos->b * sin(axis.alpha) + pos->c * cos(axis.alpha);
	pos->b = n_y;
	pos->c = n_z;
}

void	pitch(t_axe axis, t_pos *pos)
{
	double	n_x;
	double	n_z;

	n_x = pos->a * cos(axis.beta) + pos->c * sin(axis.beta);
	n_z = pos->a * -sin(axis.beta) + pos->c * cos(axis.beta);
	pos->a = n_x;
	pos->c = n_z;
}

void	yaw(t_axe axis, t_pos *pos)
{
	double	n_x;
	double	n_y;

	n_x = pos->a * cos(axis.delta) + pos->b * -sin(axis.delta);
	n_y = pos->a * sin(axis.delta) + pos->b * cos(axis.delta);
	pos->a = n_x;
	pos->b = n_y;
}

int	mouse_movement(int x, int y, t_data *data)
{
	if (data->mouse.left && !data->mouse.right && data->inrendering == 0)
	{
		data->pos.x += ft_cmppos(data->mouse.vector_x, x, 5);
		data->pos.y += ft_cmppos(data->mouse.vector_y, y, 5);
		data->mouse.vector_x = x;
		data->mouse.vector_y = y;
	}
	else if (data->mouse.right && !data->mouse.left && data->rendering == 0)
	{
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
