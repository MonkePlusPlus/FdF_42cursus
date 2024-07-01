/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:25:15 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/01 17:29:20 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	*pixel;
	t_pos 	*pos;

	mlx = mlx_init();
	pixel = create_pixel(mlx);
	mlx_win = mlx_new_window(mlx, 1500, 1000, "fdf");
	pos = double_pos(make_pos(100, 100), make_pos(200, 200));
	create_square(mlx, mlx_win, pixel, pos);
	mlx_loop(mlx);
}