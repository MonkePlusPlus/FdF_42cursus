/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:41:59 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/28 21:31:52 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	check_char(char s, char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] == s)
			return (1);
		i++;
	}
	return (0);
}

t_line	*new_line(char **content)
{
	t_line	*result;

	result = (t_line *)malloc(sizeof(t_line));
	if (result == NULL)
		return (NULL);
	result->line = content;
	result->next = NULL;
	return (result);
}

void	line_add(t_line **lst, t_line *new)
{
	if (*lst == NULL)
		*lst = new;
	else if ((*lst)->next == NULL)
		(*lst)->next = new;
	else
		line_add(&(*lst)->next, new);
}

void	free_line(char **line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		free(line[i]);
		i++;
	}
	free(line);
}

void	line_clear(t_line **lst, void (*del)(char **))
{
	t_line	*current;

	while (*lst != NULL)
	{
		current = *lst;
		del((*lst)->line);
		*lst = (*lst)->next;
		free(current);
	}
	lst = NULL;
}
