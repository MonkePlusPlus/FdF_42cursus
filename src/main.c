/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:25:15 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/24 00:52:00 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
	data.var.win = mlx_new_window(data.var.mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
			"fdf");
			
	data.pos = new_pos(100, 100, 0);
	data.axis.alpha = 0.5;
	data.axis.beta = 0.5;
	data.axis.delta = 0;
	
	data.mouse.left = 0;
	data.mouse.right = 0;
	data.mouse.vector_x = SCREEN_WIDTH / 2;
	data.mouse.vector_y = SCREEN_HEIGHT / 2;
	data.mouse.rota_x = SCREEN_WIDTH / 2;
	data.mouse.rota_y = SCREEN_HEIGHT / 2;

	data.screen = create_screen();
	data.zoom = 100;
	data.rendering = 1;
	data.inrendering = 0;
	
	data.matrix = create_matrix();
	data.length = 2;
	
	mlx_loop_hook(data.var.mlx, &render_next_frame, &data);
	mlx_hook(data.var.win, 4, 1L << 2, mouse_click, &data);
	mlx_hook(data.var.win, 5, 1L << 3, mouse_release, &data);
	mlx_hook(data.var.win, 6, 1L << 13, mouse_movement, &data);
	mlx_hook(data.var.win, 2, 1L << 0, key_touch, &data);
	mlx_hook(data.var.win, 17, 1L << 19, close_window, &data);
	mlx_loop(data.var.mlx);
	return (0);
}
