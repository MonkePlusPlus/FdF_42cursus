/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:13:33 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/28 22:56:27 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	close_window(t_data *data)
{
	if (data->matrix != NULL)
		clear_tab((void **)data->matrix, data->height);
	if (data->screen != NULL)
		clear_tab((void **)data->screen, SCREEN_HEIGHT);
	//if (data->pixel)
	//	mlx_destroy_image(data->mlx, data->pixel);
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	data->win = NULL;
	if (data->mlx)
		free(data->mlx);
	exit(0);
	return (0);
}

void	clear_tab(void **tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	freeall(t_data *data)
{
	if (data->matrix != NULL)
		clear_tab((void **)data->matrix, data->height);
	if (data->screen != NULL)
		clear_tab((void **)data->screen, SCREEN_HEIGHT);
	if (data->pixel != NULL)
		mlx_destroy_image(data->mlx, data->pixel);
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	data->win = NULL;
	if (data->mlx)
		free(data->mlx);
	exit(0);
}
