/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:18:22 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/18 03:34:23 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_pipex *p)
{
	char	*cmd;
	int		i;

	// dup2(p->fd[1], STDOUT_FILENO);
	// dup2(p->f1, STDIN_FILENO);
	// close(p->fd[0]);
	i = -1;
	while (p->paths[++i])
	{
		cmd = ft_strjoin(ft_strjoin(p->paths[i], "/"), p->av[2]);
		execve(cmd, p->cmd1, p->envp);
		free(cmd);
	}
}

// void	parent_process(t_pipex *p)
// {

// }

void	pipex(t_pipex *p)
{
	pid_t	pid;

	if (pipe(p->fd) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid < 0)
		return (perror("fork: "));
	if (pid == 0)
		child_process(p);
	waitpid(pid, NULL, 0);
	// parent_process(p);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*p;

	p = init_pipex(ac, av, envp);
	pipex(p);
	free(p);
	return (0);
}
