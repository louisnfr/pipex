/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:18:22 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/20 23:35:02 by lraffin          ###   ########.fr       */
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

char	*path(char *av, char **envp)
{
	char	**paths;
	char	*path;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(ft_strjoin(paths[i], "/"), cmd);
		if (access(path, F_OK) == 0)
			return (path);
		// free(path);
		i++;
	}
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	int		pipefd[2];
	int		fd[2];
	int		status;
	pid_t	c_pid;

	errno = 0;
	(void)av;
	(void)envp;

	fd[0] = open(av[1], O_RDONLY);
	fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[0] < 0 || fd[1] < 0)
		perror("open");

	if (ac != 5)
		usage();

	if (pipe(pipefd) < 0)
		perror("pipe");

	/* CHILD ONE */
	c_pid = fork();
	if (c_pid < 0)
		perror("fork");
	if (c_pid == 0)
	{
		close(pipefd[0]);
		dup2(fd[0], STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		execve(path(av[2], envp), options(av[2]), envp);
	}

	/* CHILD TWO */
	c_pid = fork();
	if (c_pid < 0)
		perror("fork");
	if (c_pid == 0)
	{
		close(pipefd[1]);
		dup2(fd[1], STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
		// execve();
	}
	close(pipefd[0]);
	close(pipefd[1]);

	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);

	// t_pipex	*p;

	// p = init_pipex(ac, av, envp);
	// pipex(p);
	// free(p);
	return (0);
}
