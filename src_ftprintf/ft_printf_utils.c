/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:59:48 by ptheo             #+#    #+#             */
/*   Updated: 2024/06/18 17:48:06 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	print_arg_aux(char *str, va_list argptr)
{
	int	count;

	count = 0;
	if (*str == 'x')
		count = print_hexam(va_arg(argptr, int));
	else if (*str == 'X')
		count = print_hexama(va_arg(argptr, int));
	else if (*str == 'u')
		count = print_unsint(va_arg(argptr, unsigned int));
	else if (*str == '%')
	{
		write(1, "%", 1);
		count += 1;
	}
	else
		return (-1);
	return (count);
}

int	print_arg(char *str, va_list argptr)
{
	int	count;

	count = 0;
	if (*str == 'c')
		count = print_char(va_arg(argptr, unsigned int));
	else if (*str == 's')
		count = print_str(va_arg(argptr, char *));
	else if (*str == 'p')
		count = print_ptr(va_arg(argptr, void *));
	else if (*str == 'd')
		count = print_dec(va_arg(argptr, int));
	else if (*str == 'i')
		count = print_int(va_arg(argptr, int));
	else
		count = print_arg_aux(str, argptr);
	return (count);
}

int	count_nbr(int nbr)
{
	int	count;

	count = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		count++;
	}
	while (nbr > 9)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}
