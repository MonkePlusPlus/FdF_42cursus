/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:23:54 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/26 19:26:47 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	affiche_text(t_data *data)
{
	char	*x;
	char	*y;
	char	*z;
	char	*zoom;

	x = ft_itoa(data->axis.alpha);
	y = ft_itoa(data->axis.beta);
	z = ft_itoa(data->axis.delta);
	zoom = ft_itoa(data->zoom);
	mlx_string_put(data->var.mlx, data->var.win, 20, 20, WHITE, "Theo POLGAR fdf");

	mlx_string_put(data->var.mlx, data->var.win, 20, 40, RED, "Rotation x :");
	mlx_string_put(data->var.mlx, data->var.win, 100, 40, RED, x);

	mlx_string_put(data->var.mlx, data->var.win, 20, 55, GREEN, "Rotation y :");
	mlx_string_put(data->var.mlx, data->var.win, 100, 55, GREEN, y);

	mlx_string_put(data->var.mlx, data->var.win, 20, 70, BLUE, "Rotation z :");
	mlx_string_put(data->var.mlx, data->var.win, 100, 70, BLUE, z);

	mlx_string_put(data->var.mlx, data->var.win, 20, 95, WHITE, "Zoom :");
	mlx_string_put(data->var.mlx, data->var.win, 80, 95, WHITE, zoom);

	free(x);
	free(y);
	free(z);
	free(zoom);
}