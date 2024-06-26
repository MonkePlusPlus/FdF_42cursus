/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:43:57 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/01 17:29:19 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->length + x * (data->bits / 8));
	*(unsigned int*)dst = color;
}

t_data	*create_pixel(void *mlx)
{
	t_data	*pixel;
	
	pixel = (t_data *)malloc(sizeof(t_data) * 1);
	if (pixel == NULL)
		return (NULL);
	pixel->pixel = mlx_new_image(mlx, 1500, 1000);
	pixel->addr = mlx_get_data_addr(pixel->pixel, &pixel->bits, &pixel->length,
									&pixel->endian);
	return (pixel);
}

void	put_pixel(void *mlx, void *mlx_win, t_data *pixel, t_pos pos)
{
	my_mlx_pixel_put(pixel, pos.x, pos.y, 0xFFFFFFFF);
	mlx_put_image_to_window(mlx, mlx_win, pixel->pixel, 0, 0);
}