/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keytouch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:03:58 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/03 21:03:18 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int mouse_movement(int x, int y, t_data *data)
{
    if (data->left && !data->right)
    {
        ft_printf("left x = %d y = %d\n", x, y);
        data->pos.x += 1;
    }
    else if (data->right && !data->left)
    {
        ft_printf("right x = %d y = %d\n", x, y);
        data->pos.y += 1;
    }
    return (0);
}

int mouse_release(int mousecode, int x, int y, t_data *data)
{
    if (mousecode == 1)
    {
        data->left = 0;
    }
    else if (mousecode == 3)
    {
        data->right = 0;
    }
	return (0);
}

int mouse_click(int mousecode, int x, int y, t_data *data)
{
    if (mousecode == 1)
        data->left = 1;
    else if (mousecode == 3)
        data->right = 1;
	return (0);
}

int key_touch(int keycode, t_data *data)
{
	ft_printf("key : %d\n", keycode);
    return (0);
}