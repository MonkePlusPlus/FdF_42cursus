/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:51:24 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/04 19:25:06 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    create_backgound(t_var  var, t_pixel *pixel)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < SCREEN_HEIGHT)
    {
        while (j < SCREEN_WIDTH)
        {
            put_pixel(var, pixel, make_pos(j, i), WHITE);
            j++;
        }
        j = 0;
        i++;
    }
}