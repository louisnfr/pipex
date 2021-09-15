/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:18:22 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/15 19:17:11 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
open_pipes()
{
	int **end;
	end = malloc(sizeof(int *) * 2);
	end[i] = malloc(4 * 2);
	int i = -1;
	while (++i < 2 + 1)
		pipe(end);
}
pipex()
{
	int pid;
	int infile;
	int outfile;
	char **cmd;
	int i = -1;
	open_pipes(); // 2 + 1
	while (++i < 2)
	{
		pid = fork();
		if (pid == 0)
		{
			infile = open(argv[1], O_RDONLY, 0644);
			dup2(infile, STDIN_FILENO);
			close(end[i][0]);
			dup2(end[i][1], STDOUT_FILENO);
			close(end[i][1]);
			paths
			cmd = ft_split(argv[2], ' ');
			execve;
		}
	}
	parent_process(
		i = -1;
		outfile = open(argv[4], O_WRONLY | o_CREAT | O_TRUNC, 0644);
		dup2(pipe[1][0], STDIN_FILENO);
		close(pipe[1][0]);
		dup2(outfile, STDOUT_FILENO);
		while (++i < 2)
			wait(0);
	)
}

int	main(int ac, char **av, char **envp)
{

	pipex();
	return (0);
}
