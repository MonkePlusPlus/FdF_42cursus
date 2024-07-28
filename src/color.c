/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:04:48 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/28 17:50:08 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_color	new_color(int color1, int color2)
{
	t_color color;

	color.start = color1;
	color.end = color2;
	return (color);
}

int	pick_color(t_pos pos)
{
	int	y;

	y = -pos.j;
	if (y >= 10)
		return (RED);
	else if (y >= 20)
		return (GREEN);
	else if (y >= 30)
		return (BLUE);
	return (WHITE);
}

t_color	full_color(t_pos pos1, t_pos pos2)
{
	t_color	color;

	if (-pos1.j > -pos2.j)
	{	
		color.end = pick_color(pos1);
		color.start = pick_color(pos2);}
	else
	{
		color.start = pick_color(pos1);
		color.end = pick_color(pos2);
	}
	return (color);
}