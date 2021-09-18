/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:18:22 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/18 02:07:31 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	child_process(int f1, char **cmd1)
// {



// }

// void	pipex(t_pipex *px)
// {
// 	int end[2];
// 	int	pid;

// 	char **cmd1;
// 	char **cmd2;
// 	cmd1 = ft_split(av[2], 32);
// 	cmd1 = ft_split(av[3], 32);


// 	pipe(end);
// 	pid = fork();
// 	if (fork < 0)
// 		return (perror("fork: "));
// 	if (fork == 0)
// 		child_process(f1, cmd1);
// 	else
// 		parent_process(f2, cmd2);
// }

int	main(int ac, char **av, char **envp)
{
	t_pipex	*px;

	if (ac != 5)
		return (-1);
	px = malloc(sizeof(t_pipex));
	px->envp = envp;
	get_paths(px);
	for(int q=0; px->paths[q]; q++)
		printf("px->paths[%d]: %s\n", q, px->paths[q]);
	px->av = av;
	px->f1 = open(av[1], O_RDONLY);
	px->f2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (px->f1 < 0 || px->f2 < 0)
		return (-1);
	// pipex(px);
	free(px);
	return (0);
}
