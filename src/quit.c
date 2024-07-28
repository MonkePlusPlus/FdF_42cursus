/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:13:33 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/28 20:15:47 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	close_window(int keycode, t_data *data)
{

	//if (data->var.mlx != NULL)
	//	free(data->var.mlx);
	mlx_loop_end(data->mlx);
}

void    freeall(t_data *data)
{
    if (data->matrix)
    {
        
    }
}