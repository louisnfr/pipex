/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:47:42 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/17 18:51:14 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(int c)
{
	return (c == 32);
}

int	ft_str_digit(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (ft_isdigit(s[i]) || is_space(s[i]) || s[i] == '-')
			i++;
		else
			return (0);
	}
	return (1);
}
