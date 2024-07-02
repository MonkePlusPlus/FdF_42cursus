/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keytouch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:03:58 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/02 17:42:31 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int mouse_movement(int x, int y, t_var *var)
{
    printf("yo\n");
    return (0);
}

int click_mouse(int keycode, t_var *var)
{
    if (keycode == 1)
    {
        mlx_hook(var->mlx, 6, 0L, mouse_movement, var);
    }
    return (0);
}