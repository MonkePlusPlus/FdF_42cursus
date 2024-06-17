/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:00:24 by ptheo             #+#    #+#             */
/*   Updated: 2024/05/28 13:36:40 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_char(char c)
{
	ft_putchar(c);
	return (1);
}

int	print_str(char *str)
{
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(str);
	return (ft_strlen(str));
}

int	print_ptr(void *ptr)
{
	uintptr_t	*nbr;

	nbr = (uintptr_t *)ptr;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (print_hexaptr((unsigned long long)nbr) + 2);
}

int	print_dec(long dec)
{
	size_t	count;

	count = 0;
	if (dec < 0)
	{
		write(1, "-", 1);
		dec = -dec;
		count++;
	}
	count += ft_putnbr(dec);
	return (count);
}

int	print_int(long nbr)
{
	size_t	count;

	count = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		count++;
	}
	count += ft_putnbr(nbr);
	return (count);
}
