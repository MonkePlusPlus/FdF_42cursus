/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:45:18 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/01 17:29:18 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	create_line(void *mlx, void *mlx_win, t_data *pixel, t_pos *pos)
{
	int	x;
	int	y;
	int	n;
	int	max;

	n = 0;
	x = pos[1].x - pos[0].x;
	y = pos[1].y - pos[0].y;
	max = fmax(abs(x), abs(y));
	x /= max;
	y /= max;
	while (n < max)
	{
		put_pixel(mlx, mlx_win, pixel, pos[0]);
		pos[0].x += x;
		pos[0].y += y;
		n++;
	}
}

t_pos	make_pos(int x, int y)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

t_pos	*double_pos(t_pos pos1, t_pos pos2)
{
	t_pos	*pos;

	pos = (t_pos *)malloc(sizeof(t_pos) * 2);
	if (pos == NULL)
		return (NULL);
	pos[0] = pos1;
	pos[1] = pos2;
	return (pos);
}

void	create_square(void *mlx, void *mlx_win, t_data *pixel, t_pos *pos)
{
	t_pos	posa;
	t_pos	posb;

	posa = make_pos(pos[0].x, pos[1].y);
	posb = make_pos(pos[1].x, pos[0].y);
	create_line(mlx, mlx_win, pixel, double_pos(posa, pos[0]));
	create_line(mlx, mlx_win, pixel, double_pos(posa, pos[1]));
	create_line(mlx, mlx_win, pixel, double_pos(posb, pos[0]));
	create_line(mlx, mlx_win, pixel, double_pos(posb, pos[1]));
}