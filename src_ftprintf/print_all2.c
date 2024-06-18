/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:24:45 by ptheo             #+#    #+#             */
/*   Updated: 2024/06/18 17:48:04 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	print_hexam(unsigned int nbr)
{
	size_t	count;
	char	c;

	count = 0;
	if (nbr > 15)
	{
		count += print_hexam(nbr / 16);
		c = HEXA_MIN[nbr % 16];
		write(1, &c, 1);
		count += 1;
	}
	else
	{
		c = HEXA_MIN[nbr];
		write(1, &c, 1);
		count += 1;
	}
	return (count);
}

int	print_hexama(unsigned int nbr)
{
	size_t	count;
	char	c;

	count = 0;
	if (nbr > 15)
	{
		count += print_hexama(nbr / 16);
		c = HEXA_MAJ[nbr % 16];
		write(1, &c, 1);
		count++;
	}
	else
	{
		c = HEXA_MAJ[nbr];
		write(1, &c, 1);
		count++;
	}
	return (count);
}

int	print_unsint(unsigned int nbr)
{
	char	c;
	int		count;

	count = 0;
	if (nbr > 9)
	{
		count += print_unsint(nbr / 10);
		c = (nbr % 10) + '0';
		write(1, &c, 1);
		count++;
	}
	else
	{
		c = nbr + '0';
		write(1, &c, 1);
		count++;
	}
	return (count);
}

int	print_hexaptr(unsigned long long nbr)
{
	size_t	count;
	char	c;

	count = 0;
	if (nbr > 15)
	{
		count += print_hexaptr(nbr / 16);
		c = HEXA_MIN[nbr % 16];
		write(1, &c, 1);
		count += 1;
	}
	else
	{
		c = HEXA_MIN[nbr];
		write(1, &c, 1);
		count += 1;
	}
	return (count);
}
