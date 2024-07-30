/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:43:57 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/30 15:17:47 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	clear_pixel(t_pixel *pixel)
{
	ft_bzero(pixel->addr, SCREEN_HEIGHT * SCREEN_WIDTH * pixel->bits);
}

void	my_mlx_pixel_put(t_pixel *pixel, int x, int y, int color)
{
	char	*dst;
	int		i;

	i = pixel->bits - 8;
	dst = pixel->addr + (y * pixel->length + x * (pixel->bits / 8));
	while (i >= 0)
	{
		if (pixel->endian != 0)
			*dst++ = (color >> i) & 0xFF;
		else
			*dst++ = (color >> (pixel->bits - 8 - i)) & 0xFF;
		i -= 8;
	}
}

t_pixel	*create_pixel(void *mlx)
{
	t_pixel	*pixel;

	pixel = (t_pixel *)malloc(sizeof(t_pixel) * 1);
	if (pixel == NULL)
		return (NULL);
	pixel->pixel = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (pixel->pixel == NULL)
		return (free(pixel), pixel = NULL, NULL);
	pixel->addr = mlx_get_data_addr(pixel->pixel, &pixel->bits, &pixel->length,
			&pixel->endian);
	return (pixel);
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	if (x < SCREEN_WIDTH && y < SCREEN_HEIGHT && x > 0 && y > 0)
		my_mlx_pixel_put(data->pixel, x, y, color);
}
