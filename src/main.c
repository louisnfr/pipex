/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:18:22 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/20 17:31:51 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// MISSING ERROR HANDLING
// PROTECT STRJOIN

void	child_process(t_pipex *p)
{
	char	*cmd;
	int		i;

	if (dup2(p->f1, STDIN_FILENO) < 0 || dup2(p->end[1], STDOUT_FILENO) < 0)
		terminate("child dup failed\n", p);
	close(p->end[0]);
	close(p->f1);
	i = -1;
	printf("check\n");
	while (p->paths[++i])
	{
		cmd = ft_strjoin(ft_strjoin(p->paths[i], "/"), p->av[2]);
		printf("%s\n", cmd);
		execve(cmd, p->cmd1, p->envp);
		free(cmd);
	}
	terminate("command not found\n", p);
}

void	parent_process(t_pipex *p)
{
	char	*cmd;
	int		status;
	int		i;

	waitpid(-1, &status, 0);
	if (dup2(p->f2, STDOUT_FILENO) < 0 || dup2(p->end[0], STDIN_FILENO) < 0)
		terminate("parent dup failed\n", p);
	close(p->end[1]);
	close(p->f2);
	i = -1;
	printf("check\n");
	while (p->paths[++i])
	{
		cmd = ft_strjoin(ft_strjoin(p->paths[i], "/"), p->av[3]);
		printf("-%s-\n", cmd);
		execve(cmd, p->cmd2, p->envp);
		free(cmd);
	}
	terminate("command not found\n", p);
}

void	pipex(t_pipex *p)
{
	pid_t	pid;

	if (pipe(p->end) == -1)
		return (perror("pipe: "));
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

	char *salut = malloc(15);
	(void)salut;
	p = init_pipex(ac, av, envp);
	pipex(p);
	// free(p);
	return (0);
}
