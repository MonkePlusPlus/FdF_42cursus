/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:43:57 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/03 22:55:50 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_pixel *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->length + x * (data->bits / 8));
	*(unsigned int*)dst = color;
}

t_pixel	*create_pixel(void *mlx)
{
	t_pixel	*pixel;
	
	pixel = (t_pixel *)malloc(sizeof(t_pixel) * 1);
	if (pixel == NULL)
		return (NULL);
	pixel->pixel = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	pixel->addr = mlx_get_data_addr(pixel->pixel, &pixel->bits, &pixel->length,
									&pixel->endian);
	return (pixel);
}

void	put_pixel(t_var var, t_pixel *pixel, t_pos pos)
{
	my_mlx_pixel_put(pixel, pos.x, pos.y, 0xFFFFFFFF);
	mlx_put_image_to_window(var.mlx, var.win, pixel->pixel, 0, 0);
}