/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put0xhexa_ret.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:05:41 by lraffin           #+#    #+#             */
/*   Updated: 2021/06/22 12:13:13 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put0xhexa_ret(unsigned long n, const char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_put0xhexa_ret(n / 16, base);
	count += write(1, &base[n % 16], 1);
	return (count);
}
