/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:45:18 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/23 18:31:40 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	create_line(t_data *data, t_pos pos0, t_pos pos1)
{
	int	x;
	int	y;
	int	n;
	int	max;

	n = 0;
	x = pos1.x - pos0.x;
	y = pos1.y - pos0.y;
	max = fmax(abs(x), abs(y));
	if (max != 0)
	{
		x /= max;
		y /= max;
	}
	while (n < max)
	{
		if (pos0.x > 0 && pos0.x < SCREEN_HEIGHT && pos0.y > 0
			&& pos0.y < SCREEN_WIDTH)
		{
			if (data->screen[pos0.x][pos0.y] == 0)
			{
				put_pixel(data, pos0.x, pos0.y, WHITE);
				data->screen[pos0.x][pos0.y] = 1;
			}
		}
		pos0.x += x;
		pos0.y += y;
		n++;
	}
}

t_pos	new_pos(int x, int y, int z)
{
	t_pos	pos;

	pos.i = x;
	pos.j = y;
	pos.z = z;
	return (pos);
}

void	create_field(t_data *data)
{
	t_pos	**mat;
	int			i;
	int			j;

	i = 0;
	mat = data->matrix;
	data->inrendering = 1;
	while (i < data->length)
	{
		j = 0;
		while (j < data->length)
		{
			mat[i][j].a = mat[i][j].i;
			mat[i][j].b = mat[i][j].j;
			mat[i][j].c = mat[i][j].z;
			//printf("AVANT a = %f b = %f c = %f\n", mat[i][j].a, mat[i][j].b, mat[i][j].c);
			roll(data->axis, &mat[i][j]);
			//printf("APRES a = %f b = %f c = %f\n", mat[i][j].a, mat[i][j].b, mat[i][j].c);
			pitch(data->axis, &mat[i][j]);
			yaw(data->axis, &mat[i][j]);
			mat[i][j].x = (int)(data->zoom * mat[i][j].a) + (SCREEN_WIDTH / 2);
			mat[i][j].y = (int)(data->zoom * mat[i][j].b) + (SCREEN_HEIGHT / 2);
			//printf("i = %f j = %f x = %d y = %d\n", mat[i][j].i, mat[i][j].j, mat[i][j].x, mat[i][j].y);
			if (i > 0)
				create_line(data, mat[i][j], mat[i - 1][j]);
			if (j > 0)
				create_line(data, mat[i][j], mat[i][j - 1]);
			j++;
		}
		i++;
	}
	data->inrendering = 0;
}

t_pos	**create_matrix()
{
	t_pos	**mat;

	mat = (t_pos **)malloc(sizeof(t_pos *) * 2);
	mat[0] = (t_pos *)malloc(sizeof(t_pos) * 2);
	mat[1] = (t_pos *)malloc(sizeof(t_pos) * 2);
	mat[0][0] = new_pos(0, 0, 0);
	mat[0][1] = new_pos(1, 0, 0);
	mat[1][0] = new_pos(0, 0, 1);
	mat[1][1] = new_pos(1, 0, 1);
	return (mat);
}