/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 02:09:06 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/20 22:42:38 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	*init_pipex(int ac, char **av, char **envp)
{
	t_pipex	*p;

	if (ac != 5)
		exit (EXIT_FAILURE);
	p = malloc(sizeof(t_pipex));
	p->f1 = open(av[1], O_RDONLY);
	p->f2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (p->f1 < 0 || p->f2 < 0)
		terminate("open failed", p);
	p->cmd1 = ft_split(av[2], ' ');
	p->cmd2 = ft_split(av[3], ' ');
	p->envp = envp;
	p->av = av;
	get_paths(p);
	return (p);
}

void	usage(void)
{
	write(2, "usage: ./pipex [file1] [cmd1] [cmd2] [file2]\n", 45);
	exit(EXIT_FAILURE);
}

void	terminate(char *error, t_pipex *p)
{
	if (errno == 0)
		write(2, error, ft_strlen(error));
	else
		perror(error);
	free(p);
	exit(EXIT_FAILURE);
}
