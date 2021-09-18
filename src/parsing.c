/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 01:21:28 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/18 02:04:53 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_paths(t_pipex *px)
{
	char	*path;
	int		i;

	i = -1;
	while (px->envp[++i])
		if (ft_strnstr(px->envp[i], "PATH=", 5))
			break ;
	path = ft_substr(px->envp[i], 5, ft_strlen(px->envp[i]));
	px->paths = ft_split(path, ':');
}
