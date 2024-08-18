/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:34:29 by ptheo             #+#    #+#             */
/*   Updated: 2024/08/18 18:55:35 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	hexa_six(char *color, t_color *result)
{
	int		cara;
	int		i;
	int		p;

	i = 6;
	p = 0;
	while (--i >= 0)
	{
		if (color[i] >= 'a' && color[i] <= 'f')
			cara = 10 + (color[i] - 'a');
		else if (color[i] >= '0' && color[i] <= '9')
			cara = color[i] - '0';
		else
			cara = 0;
		if (i > 3)
			result->blue += (cara * pow(16, p));
		else if (i > 1)
			result->green += (cara * pow(16, p));
		else
			result->red += (cara * pow(16, p));
		p++;
		if (p > 1)
			p = 0;
	}
}

void	hexa_four(char *color, t_color *result)
{
	int		cara;
	int		i;
	int		p;

	i = 4;
	p = 0;
	while (--i >= 0)
	{
		if (color[i] >= 'a' && color[i] <= 'f')
			cara = 10 + (color[i] - 'a');
		else if (color[i] >= '0' && color[i] <= '9')
			cara = color[i] - '0';
		else
			cara = 0;
		if (i > 1)
			result->blue += (cara * pow(16, p));
		else
			result->green += (cara * pow(16, p));
		p++;
		if (p > 1)
			p = 0;
	}
}

void	hexa_two(char *color, t_color *result)
{
	int		cara;
	int		i;
	int		p;

	i = 2;
	p = 0;
	while (--i >= 0)
	{
		if (color[i] >= 'a' && color[i] <= 'f')
			cara = 10 + (color[i] - 'a');
		else if (color[i] >= '0' && color[i] <= '9')
			cara = color[i] - '0';
		else
			cara = 0;
		result->blue += (cara * pow(16, p));
		p++;
		if (p > 1)
			p = 0;
	}
}

t_color	char_to_hexa(char *color)
{
	t_color	result;
	int		size;

	result.red = 0;
	result.blue = 0;
	result.green = 0;
	size = ft_strlen(color);
	if (size == 6)
		hexa_six(color, &result);
	else if (size == 4)
		hexa_four(color, &result);
	else
		hexa_two(color, &result);
	return (result);
}
