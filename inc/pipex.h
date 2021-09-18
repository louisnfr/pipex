/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:05:40 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/18 03:39:08 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_pipex
{
	char	**paths;
	char	**cmd1;
	char	**cmd2;
	char	**envp;
	char	**av;
	int		end[2];
	int		f1;
	int		f2;
}	t_pipex;

t_pipex	*init_pipex(int ac, char **av, char **envp);
void	get_paths(t_pipex *p);

#endif
