/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keytouch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:03:58 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/03 19:52:31 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int left_mouse_movement(int x, int y, t_data *data)
{
	ft_printf("prout\n");
    ft_printf("mouse move : x = %d y = %d\n", x, y);
    return (0);
}

int right_mouse_movement(int x, int y, t_data *data)
{
    ft_printf("mouse move : x = %d y = %d\n", x, y);
    return (0);
}

int key_mouse(int mousecode, int x, int y, t_data *data)
{
	ft_printf("mousekey : %d x = %d y = %d\n", mousecode, x, y);
	return (0);
}

int key_touch(int keycode, t_data *data)
{
	ft_printf("key : %d\n", keycode);
    return (0);
}