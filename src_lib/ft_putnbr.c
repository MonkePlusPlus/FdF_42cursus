/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:47:35 by ptheo             #+#    #+#             */
/*   Updated: 2024/05/27 12:40:34 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_putnbr(unsigned long nbr)
{
	size_t	count;
	char	c;

	count = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		count += 1;
	}
	if (nbr > 9)
	{
		count += ft_putnbr(nbr / 10);
		c = (nbr % 10) + '0';
		write(1, &c, 1);
		count += 1;
	}
	else
	{
		c = (nbr % 10) + '0';
		write(1, &c, 1);
		count += 1;
	}
	return (count);
}
/*
void	ft_putnbr(int n)
{
	ft_putnbr_2(n);
}*/
