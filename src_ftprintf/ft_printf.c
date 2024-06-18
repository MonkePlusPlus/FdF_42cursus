/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:59:44 by ptheo             #+#    #+#             */
/*   Updated: 2024/06/18 17:49:49 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_printf(const char *string, ...)
{
	va_list	argptr;
	char	*str;
	int		count;

	if (!string)
		return (-1);
	va_start(argptr, string);
	str = (char *)string;
	count = 0;
	while (str && *str)
	{
		if (*str == '%')
		{
			count += print_arg(str + 1, argptr);
			str += 2;
		}
		else
		{
			write(1, str, 1);
			count++;
			str++;
		}
	}
	va_end(argptr);
	return (count);
}

int	main(void)
{
	return (0);
}
