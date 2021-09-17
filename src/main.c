/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:18:22 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/18 01:38:09 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int f1, char *cmd1)
{

}

void	pipex(int f1, int f2, char **av, char **envp)
{
	int end[2];
	int	pid;

	pipe(end);
	pid = fork();
	if (fork < 0)
		return (perror("fork: "));
	if (fork == 0)
		child_process(f1, cmd1);
	else
		parent_process(f2, cmd2);
}

int	main(int ac, char **av, char **envp)
{
	int f1;
	int f2;

	if (ac != 4)
		return (-1);
	f1 = open(av[1], O_RDONLY);
	f2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0)
		return (-1);
	pipex(f1, f2, av, envp);
	return (0);
}
