/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:28:50 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/14 18:22:37 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_touch_utils(int keycode, t_data *data)
{
	if (keycode == 110)
		data->change_color = 0;
	else if (keycode == 65362)
	{
		if (data->xhaut < 1000000)
			data->xhaut += 0.1;
	}
	else if (keycode == 65364)
	{
		if (data->xhaut > -1000000)
			data->xhaut -= 0.1;
	}
	return (0);
}

void	line_maker(t_data *data, int i, int j)
{
	if (j > 0)
	{
		if (data->matrix[i][j].j < data->matrix[i][j - 1].j)
			create_line(data, data->matrix[i][j - 1], data->matrix[i][j]);
		else
			create_line(data, data->matrix[i][j], data->matrix[i][j - 1]);
	}
	if (i > 0)
	{
		if (data->matrix[i][j].j < data->matrix[i - 1][j].j)
			create_line(data, data->matrix[i - 1][j], data->matrix[i][j]);
		else
			create_line(data, data->matrix[i][j], data->matrix[i - 1][j]);
	}
}

void	create_field(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->inrendering = 1;
	while (i < data->prof)
	{
		j = -1;
		while (++j < data->width)
		{
			data->matrix[i][j].a = data->matrix[i][j].i - data->middle_y;
			data->matrix[i][j].b = data->matrix[i][j].j * data->xhaut;
			data->matrix[i][j].c = data->matrix[i][j].z - data->middle_x;
			roll(data->axis, &data->matrix[i][j]);
			pitch(data->axis, &data->matrix[i][j]);
			yaw(data->axis, &data->matrix[i][j]);
			data->matrix[i][j].x = (int)(data->zoom * data->matrix[i][j].a)
				+ (SCREEN_WIDTH / 2) + data->pos.x;
			data->matrix[i][j].y = (int)(data->zoom * data->matrix[i][j].b)
				+ (SCREEN_HEIGHT / 2) + data->pos.y;
			line_maker(data, i, j);
		}
		i++;
	}
	data->inrendering = 0;
}
