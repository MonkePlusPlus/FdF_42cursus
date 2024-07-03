/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:25:15 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/03 21:35:43 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	render_next_frame(t_data *data)
{
		
	put_pixel(data->var, data->pixel, make_pos(100 + data->pos.x, 100 + data->pos.y));
	//create_square(all->var, all->pixel, double_pos(make_pos(100, 100), make_pos(200, 200)));
	return (0);
}

int	close_window(int keycode, t_data *data)
{
	mlx_destroy_window(data->var.mlx, data->var.win);
	if (data->var.mlx != NULL)
		free(data->var.mlx);
	exit(0);
}

int	main(void)
{
	t_data	data;

	data.var.mlx = mlx_init();
	data.pixel = create_pixel(data.var.mlx);
	data.background = create_background(data.var.mlx);
	data.var.win = mlx_new_window(data.var.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "fdf");
	data.pos = make_pos(100, 100);
	data.left = 0;
	data.right = 0;
	mlx_loop_hook(data.var.mlx, render_next_frame, &data);
	mlx_hook(data.var.win, 4, 1L<<2, mouse_click, &data);
	mlx_hook(data.var.win, 5, 1L<<3, mouse_release, &data);
	mlx_hook(data.var.win, 6, 1L<<13, mouse_movement, &data);
	mlx_hook(data.var.win, 2, 1L<<0, key_touch, &data);
	mlx_hook(data.var.win, 17, 1L<<19, close_window, &data);
	mlx_loop(data.var.mlx);
	return (0);
}