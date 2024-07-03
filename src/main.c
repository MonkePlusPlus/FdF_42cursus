/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:25:15 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/03 20:05:47 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	render_next_frame(t_data *data)
{
	//put_pixel(all->var, all->pixel, make_pos(100, 100));
	//create_square(all->var, all->pixel, double_pos(make_pos(100, 100), make_pos(200, 200)));
	//mlx_mouse_hook(all->var.win, click_mouse, &all->var);
}

int	close_window(int keycode, t_data *data)
{
	mlx_destroy_window(data->var.mlx, data->var.win);
	mlx_loop_end(data->var.mlx);
	if (data->var.mlx != NULL)
		free(data->var.mlx);
	exit(0);
}

int	main(void)
{
	t_data	data;

	data.var.mlx = mlx_init();
	data.pixel = create_pixel(data.var.mlx);
	data.var.win = mlx_new_window(data.var.mlx, 1000, 1000, "fdf");
	data.pos = make_pos(100, 100);
	/* ACTION */
	mlx_loop_hook(data.var.mlx, render_next_frame, &data);
	mlx_hook(data.var.win, 4, 1L<<2, key_mouse, &data);
	//mlx_hook(data.var.win, 5, 1L<<6, left_mouse_movement, &data);
	mlx_hook(data.var.win, 6, 1L<<8, left_mouse_movement, &data);
	mlx_hook(data.var.win, 6, 1L<<10, right_mouse_movement, &data);
	mlx_hook(data.var.win, 2, 1L<<0, key_touch, &data);
	mlx_hook(data.var.win, 17, 1L<<19, close_window, &data);
	mlx_loop(data.var.mlx);
	return (0);
}