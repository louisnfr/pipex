/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 01:21:28 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/18 03:45:40 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_paths(t_pipex *p)
{
	char	*path;
	int		i;

	i = -1;
	while (p->envp[++i])
		if (ft_strnstr(p->envp[i], "PATH=", 5))
			break ;
	path = ft_substr(p->envp[i], 5, ft_strlen(p->envp[i]));
	p->paths = ft_split(path, ':');
	// si probleme leaks, opt: paths = ft_split(envp[i] + 5, ':');
}
