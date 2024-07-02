/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:25:15 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/02 18:03:58 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	render_next_frame(t_all *all)
{
	create_square(all->var, all->pixel, double_pos(make_pos(100, 100), make_pos(200, 200)));
	//mlx_mouse_hook(all->var.win, click_mouse, &all->var);
	return (0);
}

int	main(void)
{
	t_pos 	*pos;
	t_all	*all;

	all = (t_all *)malloc(sizeof(t_all) * 1);
	if (all == NULL)
		return (0);
	all->var.mlx = mlx_init();
	all->pixel = create_pixel(all->var.mlx);
	all->var.win = mlx_new_window(all->var.mlx, 1500, 1000, "fdf");
	pos = double_pos(make_pos(0, 0), make_pos(0, 0));
	//mlx_hook(var.mlx, 6, 1L<<6, mouse_movement, &var);
	mlx_loop_hook(all->var.mlx, render_next_frame, all);
	mlx_loop(all->var.mlx);
}