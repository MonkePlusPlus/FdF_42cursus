/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:51:24 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/28 20:08:04 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    free_tab(int **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	**create_screen()
{
	int	**tab;
	int	i;
	i = 0;
	tab = (int **)malloc(sizeof(int *) * SCREEN_HEIGHT);
	if (tab == NULL)
	return (NULL);
	while (i < SCREEN_HEIGHT)
	{
		tab[i] = (int *)malloc(sizeof(int *) * SCREEN_WIDTH);
		if (tab[i] == NULL)
			return (free_tab(tab, i), NULL);
		ft_bzero(tab[i], SCREEN_WIDTH);
		i++;
	}
	return (tab);
}

void	create_backgound(t_data *data)
{
	t_pos	pos;
	int		i;
	int		j;

	data->inrendering = 1;
	//ft_printf("rendering background\n");
	i = 0;
	j = 0;
	while (i < SCREEN_HEIGHT)
	{
		while (j < SCREEN_WIDTH)
		{
			if (data->screen[i][j] == 1)
			{
				put_pixel(data, j, i, BLACK);
				data->screen[i][j] = 0;
			}
			j++;
		}
		j = 0;
		i++;
	}
	data->inrendering = 0;
}