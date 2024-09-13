/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:04:48 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/13 18:37:25 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_color	pick_color(long color)
{
	t_color	final;

	final.blue = color % 255;
	if (final.blue == 0 && color % 16 == 15)
		final.blue = 255;
	color /= 256;
	final.green = color % 255;
	if (final.green == 0 && color % 16 == 15)
		final.green = 255;
	color /= 256;
	final.red = color % 255;
	if (final.red == 0 && color % 16 == 15)
		final.red = 255;
	return (final);
}

t_color	new_color(t_color color, t_color color2)
{
	if (color.red < color2.red)
		color.red += 1;
	else if (color.blue < color2.blue)
		color.blue += 1;
	else if (color.green < color2.green)
		color.green += 1;
	return (color);
}

long	hexa_color(t_color color)
{
	long	final;

	final = 0x00000000;
	final += (color.red * 256 * 256);
	final += (color.green * 256);
	final += (color.blue);
	return (final);
}

t_color	get_color(char **color)
{
	t_color	final;

	final = char_to_hexa(color[1] + 2);
	free_line(color);
	return (final);
}

t_color	select_color(t_data *data, char *line)
{
	char	**number;

	number = better_split(line, ",");
	if (number[1] != NULL)
		return (get_color(number));
	return (pick_color(data->color));
}
