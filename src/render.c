/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 22:33:24 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/23 17:38:46 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	render_next_frame(t_data *data)
{
	create_backgound(data);
	if (data->inrendering == 0)
	{
		create_field(data);
	}
	mlx_put_image_to_window(data->var.mlx, data->var.win, data->pixel->pixel, 0, 0);
	return (0);
}