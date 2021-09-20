/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ret.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:50:43 by lraffin           #+#    #+#             */
/*   Updated: 2021/06/17 17:42:03 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_ret(int n)
{
	long	nbr;
	int		count;

	nbr = n;
	count = 0;
	if (nbr < 0)
		nbr = -nbr;
	if (nbr > 9)
	{
		count += ft_putnbr_ret(nbr / 10);
		count += ft_putnbr_ret(nbr % 10);
	}
	else
		count += ft_putchar_ret(nbr + 48);
	return (count);
}
