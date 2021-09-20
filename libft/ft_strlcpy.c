/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:21:00 by lraffin           #+#    #+#             */
/*   Updated: 2021/04/18 23:39:30 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	len;

	if (!dst || !src)
		return (0);
	srcsize = ft_strlen(src);
	if (dstsize)
	{
		if (srcsize >= dstsize)
			len = dstsize - 1;
		else
			len = srcsize;
		ft_memcpy(dst, src, len);
		dst[len] = 0;
	}
	return (srcsize);
}
