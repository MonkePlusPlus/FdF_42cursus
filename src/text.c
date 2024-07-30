/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:23:54 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/30 15:19:57 by ptheo            ###   ########.fr       */
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
	if (x && y && z && zoom)
	{
		mlx_string_put(data->mlx, data->win, 20, 20, WHITE, "Theo POLGAR fdf");
		mlx_string_put(data->mlx, data->win, 20, 40, RED, "Rotation x :");
		mlx_string_put(data->mlx, data->win, 100, 40, RED, x);
		mlx_string_put(data->mlx, data->win, 20, 55, GREEN, "Rotation y :");
		mlx_string_put(data->mlx, data->win, 100, 55, GREEN, y);
		mlx_string_put(data->mlx, data->win, 20, 70, BLUE, "Rotation z :");
		mlx_string_put(data->mlx, data->win, 100, 70, BLUE, z);
		mlx_string_put(data->mlx, data->win, 20, 95, WHITE, "Zoom :");
		mlx_string_put(data->mlx, data->win, 80, 95, WHITE, zoom);
		mlx_string_put(data->mlx, data->win, 20, 150, WHITE, "| TOUCH SUMMARY |");
		mlx_string_put(data->mlx, data->win, 20, 180, WHITE, "I : isometric view");
		mlx_string_put(data->mlx, data->win, 20, 195, WHITE, "SPACE : go back center");
	}
	if (x)
		free(x);
	if (y)
		free(y);
	if (z)
		free(z);
	if (zoom)
		free(zoom);
}
