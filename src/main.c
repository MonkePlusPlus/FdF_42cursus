/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:25:15 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/30 15:18:32 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	t_line	*map;
	t_data	data;
	int		fd;

	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (1);
		data.mlx = mlx_init();
		if (data.mlx == NULL)
			return (1);
		data.win = mlx_new_window(data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
				"fdf");
		if (data.win == NULL)
			return (free(data.mlx), 1);
		data.pixel = create_pixel(data.mlx);
		if (data.pixel == NULL || data.pixel->pixel == NULL)
			return (free(data.mlx), free(data.win), 1);
		data.axis.alpha = 49 * M_PI / 180;
		data.axis.beta = 35.264 * M_PI / 180;
		data.axis.delta = 30.736 * M_PI / 180;
	/*
		data.axis.alpha = 0;
		data.axis.beta = 90 * M_PI / 180;
		data.axis.delta = 0;
*/
		data.mouse.left = 0;
		data.mouse.right = 0;
		data.mouse.vector_x = SCREEN_WIDTH / 2;
		data.mouse.vector_y = SCREEN_HEIGHT / 2;
		data.mouse.rota_x = SCREEN_WIDTH / 2;
		data.mouse.rota_y = SCREEN_HEIGHT / 2;

		data.screen = create_screen();
		if (data.screen == NULL)
			return (freeall(&data), 1);
		data.rendering = 1;
		data.inrendering = 0;
		
		data.height = 0;
		map = create_map(fd, &data);
		if (map == NULL)
			return (freeall(&data), 1);
		//print_map(map);
		maplen(map, &data);
		data.middle_x = (double)data.width / 2;
		data.middle_y = (double)data.prof / 2;
		data.matrix = create_matrix(map, &data);
		if (data.matrix == NULL)
			return (freeall(&data), 1);
		//data.middle_x = (double)data.width / 4;
		//data.middle_y = (double)data.height / 4;
		data.zoom = fmin(800 / (data.width), 800 / (data.prof));
		data.pos.x = 0;
		data.pos.y = 0;

		mlx_loop_hook(data.mlx, &render_next_frame, &data);
		mlx_hook(data.win, 17, 1L << 19, &close_window, &data);
		mlx_hook(data.win, 4, 1L << 2, &mouse_click, &data);
		mlx_hook(data.win, 5, 1L << 3, &mouse_release, &data);
		mlx_hook(data.win, 6, 1L << 13, &mouse_movement, &data);
		mlx_hook(data.win, 2, 1L << 0, &key_touch, &data);
		mlx_loop(data.mlx);
		//freeall(&data);
		
		close(fd);
	}
	return (0);
}
