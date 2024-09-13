/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:45:18 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/13 18:53:02 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	check_pixel(t_data *data, t_pos pos0, t_pos pos1)
{
	if (pos0.x > 0 && pos0.x < SCREEN_WIDTH && pos0.y > 0
		&& pos0.y < SCREEN_HEIGHT)
	{
		if (data->change_color)
			put_pixel(data, pos0.x, pos0.y, data->color);
		else
			put_pixel(data, pos0.x, pos0.y, hexa_color(pos0.color));
		data->screen[(int)pos0.y][(int)pos0.x] = 1;
	}
}

void	create_line(t_data *data, t_pos pos0, t_pos pos1)
{
	double	x;
	double	y;
	int		n;
	double	max;

	n = 0;
	x = pos1.x - pos0.x;
	y = pos1.y - pos0.y;
	max = sqrt(x * x + y * y);
	if (max > 0)
	{
		x /= max;
		y /= max;
	}
	while (n <= max)
	{
		check_pixel(data, pos0, pos1);
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

int	create_pos(t_data *data, t_line *current, t_pos *mat, int i)
{
	int	j;
	int	y;

	j = 0;
	while (j < data->width)
	{
		if (check_number(current->line[j]) == -1)
			return (-1);
		y = ft_atoi(current->line[j]);
		while (y > 100)
			y /= 10;
		mat[j] = new_pos(i, -y, j);
		mat[j].color = select_color(data, current->line[j]);
		j++;
	}
	return (0);
}

t_pos	**create_matrix(t_line *map, t_data *data)
{
	t_pos	**mat;
	t_line	*current;
	int		y;
	int		i;

	i = 0;
	current = map;
	mat = (t_pos **)malloc(sizeof(t_pos *) * data->prof);
	if (mat == NULL)
		return (line_clear(&map, &free_line), NULL);
	while (i < data->prof)
	{
		mat[i] = (t_pos *)malloc(sizeof(t_pos) * data->width);
		if (mat[i] == NULL || (create_pos(data, current, mat[i], i) == -1))
			return (line_clear(&map, &free_line),
				clear_tab((void **)mat, i + 1), ft_putstr_fd("Error pos\n", 2),
				NULL);
		i++;
		current = current->next;
	}
	line_clear(&map, &free_line);
	return (mat);
}
