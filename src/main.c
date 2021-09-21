/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:18:22 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/21 17:39:14 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_one(int *pipefd, int *fd, char **av, char **envp)
{
	char	**cmd;
	pid_t	c_pid;

	c_pid = fork();
	if (c_pid < 0)
		terminate();
	if (c_pid == 0)
	{
		fd[0] = open(av[1], O_RDONLY);
		cmd = ft_split(av[2], ' ');
		close(pipefd[0]);
		dup2(fd[0], STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		if (cmd[0] && path(cmd[0], envp))
		{
			execve(path(cmd[0], envp), cmd, envp);
			free_split(cmd);
		}
		else
		{
			cmd_not_found(cmd[0]);
			free_split(cmd);
		}
	}
}

void	child_two(int *pipefd, int *fd, char **av, char **envp)
{
	char	**cmd;
	pid_t	c_pid;

	c_pid = fork();
	if (c_pid < 0)
		terminate();
	if (c_pid == 0)
	{
		fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		cmd = ft_split(av[3], ' ');
		close(pipefd[1]);
		dup2(fd[1], STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
		if (cmd[0] && path(cmd[0], envp))
		{
			execve(path(cmd[0], envp), cmd, envp);
			free_split(cmd);
		}
		else
		{
			cmd_not_found(cmd[0]);
			free_split(cmd);
		}
	}
}

int	main(int ac, char **av, char **envp)
{
	int	pipefd[2];
	int	fd[2];
	int	status;

	errno = 0;
	if (ac != 5)
		usage();
	if (pipe(pipefd) < 0)
		terminate();
	child_one(pipefd, fd, av, envp);
	child_two(pipefd, fd, av, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
	return (0);
}
