/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:25:15 by ptheo             #+#    #+#             */
/*   Updated: 2024/06/30 22:34:30 by ptheo            ###   ########.fr       */
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

void	put_pixel(void *mlx, void *mlx_win, t_data *pixel, int x, int y)
{
	my_mlx_pixel_put(pixel, x, y, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, pixel->pixel, 0, 0);
}

void	create_ver_line(void *mlx, void *mlx_win, t_data *pixel, int pos_start[2], int pos_end[2])
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	
	{
		put_pixel(mlx, mlx_win, pixel, pos_start[0] + pos_end[0], pos_start[1] + pos_end[1]);
		i++;
	}
}

void	create_square(void *mlx, void *mlx_win, t_data *pixel, int length, int pos[2])
{


}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	*pixel;
	int		pos[2];

	mlx = mlx_init();
	pixel = create_pixel(mlx);
	mlx_win = mlx_new_window(mlx, 1500, 1000, "fdf");
	pos[0] = 100;
	pos[1] = 100;
	create_ver_line(mlx, mlx_win, pixel, 100, pos);
	mlx_loop(mlx);
}