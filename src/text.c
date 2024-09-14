/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:23:54 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/14 18:16:15 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	affiche_text_rota(t_data *data)
{
	char	*x;
	char	*y;
	char	*z;

	x = ft_itoa(data->axis.alpha);
	y = ft_itoa(data->axis.beta);
	z = ft_itoa(data->axis.delta);
	if (x && y && z)
	{
		mlx_string_put(data->mlx, data->win, 20, 20, WHITE, "Theo POLGAR fdf");
		mlx_string_put(data->mlx, data->win, 20, 40, RED, "Rotation x :");
		mlx_string_put(data->mlx, data->win, 100, 40, RED, x);
		mlx_string_put(data->mlx, data->win, 20, 55, GREEN, "Rotation y :");
		mlx_string_put(data->mlx, data->win, 100, 55, GREEN, y);
		mlx_string_put(data->mlx, data->win, 20, 70, BLUE, "Rotation z :");
		mlx_string_put(data->mlx, data->win, 100, 70, BLUE, z);
	}	
	if (x)
		free(x);
	if (y)
		free(y);
	if (z)
		free(z);
}

void	affiche_text_res(t_data *data)
{
	char	*zoom;

	zoom = ft_itoa(data->zoom);
	if (zoom)
	{
		mlx_string_put(data->mlx, data->win, 20, 95, WHITE, "Zoom :");
		mlx_string_put(data->mlx, data->win, 80, 95, WHITE, zoom);
		mlx_string_put(data->mlx, data->win, 20, 160, WHITE,
			"| TOUCH SUMMARY |");
		mlx_string_put(data->mlx, data->win, 20, 180, WHITE,
			"I : isometric view");
		mlx_string_put(data->mlx, data->win, 20, 195, WHITE,
			"P : orthogonal projection");
		mlx_string_put(data->mlx, data->win, 20, 210, WHITE,
			"SPACE : go back center");
		mlx_string_put(data->mlx, data->win, 20, 300, WHITE,
			"| CHOSE COLOR |");
		mlx_string_put(data->mlx, data->win, 20, 320, RED, "R : RED");
		mlx_string_put(data->mlx, data->win, 20, 335, GREEN, "G : GREEN");
		mlx_string_put(data->mlx, data->win, 20, 350, BLUE, "B : BLUE");
		mlx_string_put(data->mlx, data->win, 20, 365, WHITE, "W : WHITE");
		mlx_string_put(data->mlx, data->win, 20, 380, WHITE, "N : NORMAL");
	}
	if (zoom)
		free(zoom);
}

void	affiche_text_other(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 20, 470, WHITE,
		"| CHANGE HEIGHT |");
	mlx_string_put(data->mlx, data->win, 20, 490, WHITE, "KEY_UP : +");
	mlx_string_put(data->mlx, data->win, 20, 505, WHITE, "KEY_DOWN : -");
}

void	affiche_text(t_data *data)
{
	affiche_text_rota(data);
	affiche_text_res(data);
	affiche_text_other(data);
}
