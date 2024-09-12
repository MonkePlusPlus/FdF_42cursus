/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:49:18 by ptheo             #+#    #+#             */
/*   Updated: 2024/09/12 17:04:26 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_line(char **line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		ft_printf("%s ", line[i]);
		i++;
	}
	ft_printf("\n");
}

void	print_map(t_line *map)
{
	t_line	*current;

	current = map;
	while (current)
	{
		print_line(current->line);
		current = current->next;
	}
}

void	maplen(t_line *list, t_data *data)
{
	t_line	*current;
	int		count;
	int		i;

	count = 0;
	i = 0;
	current = list;
	while (current)
	{
		count++;
		current = current->next;
	}
	while (list->line[i])
		i++;
	data->prof = count;
	data->width = i;
}

t_line	*create_map(int fd, t_data *data)
{
	t_line	*start;
	t_line	*list;
	char	**list_line;
	char	*line;

	start = NULL;
	line = get_next_line(fd);
	while (line)
	{
		list_line = better_split(line, WHITE_SPACE);
		if (list_line == NULL)
			return (line_clear(&list, &free_line), free(line), NULL);
		list = new_line(list_line);
		line_add(&start, list);
		free(line);
		line = get_next_line(fd);
	}
	return (start);
}
