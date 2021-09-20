/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 00:28:48 by lraffin           #+#    #+#             */
/*   Updated: 2021/06/10 18:04:00 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbrlen(long n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ret;
	long	nb;
	size_t	len;

	nb = n;
	len = nbrlen(n);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ret[len--] = 0;
	if (n == 0)
		ret[0] = '0';
	if (nb < 0)
	{
		ret[0] = '-';
		nb = -nb;
	}
	while (nb)
	{
		ret[len--] = (nb % 10) + 48;
		nb /= 10;
	}
	return (ret);
}
