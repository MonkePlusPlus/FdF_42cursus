/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 22:33:24 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/24 01:37:01 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	render_next_frame(t_data *data)
{
	create_backgound(data);
	if (data->inrendering == 0)
	{
		create_field(data);
		//create_line(data, new_pos(400, 400, 0), new_pos(442, 353, 0));
	}
	mlx_put_image_to_window(data->var.mlx, data->var.win, data->pixel->pixel, 0, 0);
	return (0);
}