/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:01:39 by lraffin           #+#    #+#             */
/*   Updated: 2021/04/19 17:13:30 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*ret;
	size_t	i;
	size_t	b;
	size_t	e;

	if (!s1 || !set)
		return (NULL);
	b = 0;
	while (s1[b] && is_charset(s1[b], set))
		b++;
	e = ft_strlen(s1);
	while (e > b && is_charset(s1[e - 1], set))
		e--;
	ret = malloc(sizeof(char) * (e - b + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (b < e)
		ret[i++] = s1[b++];
	ret[i] = 0;
	return (ret);
}
