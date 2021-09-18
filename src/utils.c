/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 02:09:06 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/18 02:14:38 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	*init_pipex(int ac, char **av, char **envp)
{
	t_pipex	*px;

	if (ac != 5)
		exit (EXIT_FAILURE);
	px = malloc(sizeof(t_pipex));
	px->envp = envp;
	px->av = av;
	px->f1 = open(av[1], O_RDONLY);
	px->f2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (px->f1 < 0 || px->f2 < 0)
	{
		free(px);
		exit(EXIT_FAILURE);
	}
	get_paths(px);
	return (px);
}
