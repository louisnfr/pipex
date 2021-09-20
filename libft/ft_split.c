/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:39:02 by lraffin           #+#    #+#             */
/*   Updated: 2021/05/25 14:55:15 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	words;
	int		state;

	words = 0;
	state = 1;
	while (s && *s)
	{
		if (*s == c)
			state = 1;
		else if (state == 1)
		{
			words++;
			state = 0;
		}
		s++;
	}
	return (words);
}

static size_t	sizeof_word(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && (s[i] != c))
		i++;
	return (i);
}

static	char	**free_tab(char **tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(tab[i++]);
	free(tab);
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	size_t	index;
	size_t	i;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	index = 0;
	while (count_words(s, c))
	{
		while (*s == c)
			s++;
		tab[index] = malloc(sizeof(char) * (sizeof_word(s, c) + 1));
		if (!tab[index])
			return (free_tab(tab, index));
		i = 0;
		while (*s && (*s != c))
			tab[index][i++] = *s++;
		tab[index][i] = 0;
		index++;
	}
	tab[index] = 0;
	return (tab);
}
