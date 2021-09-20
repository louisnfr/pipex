/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 01:15:59 by lraffin           #+#    #+#             */
/*   Updated: 2021/04/18 01:24:41 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*d;
	size_t			i;

	d = (void *)s;
	i = 0;
	while (i < n)
	{
		if (d[i] == (unsigned char)c)
			return (&d[i]);
		i++;
	}
	return (NULL);
}
