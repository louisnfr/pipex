/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:18:22 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/16 18:19:45 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

open_pipes()
{
	int **end;
	int i = -1;

	end = malloc(sizeof(int *) * 2);
	end[i] = malloc(4 * 2);
	while (++i < 2 + 1)
		pipe(end[i]);
}
void	pipex(int f1, int f2, char **av, char **envp)
{
	char **cmd;
	int pid;
	int i = -1;

	open_pipes(); // 2 + 1
	while (++i < 2)
	{
		pid = fork();
		if (pid == 0)
		{
			dup2(f1, STDIN_FILENO);
			close(end[i][0]);
			dup2(end[i][1], STDOUT_FILENO);
			close(end[i][1]);
			get paths
			cmd = ft_split(av[2], ' ');
			execve;
		}
	}
	parent_process(
		i = -1;
		dup2(pipe[1][0], STDIN_FILENO);
		close(pipe[1][0]);
		dup2(f2, STDOUT_FILENO);
		while (++i < 2)
			wait(0);
	)
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
	free_all();
	return (0);
}
