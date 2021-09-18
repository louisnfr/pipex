/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:18:22 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/18 03:44:25 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_pipex *p)
{
	char	*cmd;
	int		i;

	dup2(p->f1, STDIN_FILENO);
	dup2(p->end[1], STDOUT_FILENO);
	close(p->end[0]);
	close(p->f1);
	i = -1;
	while (p->paths[++i])
	{
		cmd = ft_strjoin(ft_strjoin(p->paths[i], "/"), p->av[2]);
		execve(cmd, p->cmd1, p->envp);
		free(cmd);
	}
	exit(EXIT_FAILURE);
}

void	parent_process(t_pipex *p)
{
	char	*cmd;
	int		status;
	int		i;

	waitpid(-1, &status, 0);
	dup2(p->f2, STDOUT_FILENO);
	dup2(p->end[0], STDIN_FILENO);
	close(p->end[1]);
	close(p->f2);
	i = -1;
	while (p->paths[++i])
	{
		cmd = ft_strjoin(ft_strjoin(p->paths[i], "/"), p->av[2]);
		execve(cmd, p->cmd2, p->envp);
		free(cmd);
	}
	exit(EXIT_FAILURE);
}

void	pipex(t_pipex *p)
{
	pid_t	pid;

	if (pipe(p->end) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid < 0)
		return (perror("fork: "));
	if (pid == 0)
		child_process(p);
	parent_process(p);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*p;

	p = init_pipex(ac, av, envp);
	pipex(p);
	free(p);
	return (0);
}
