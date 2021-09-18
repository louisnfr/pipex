/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:05:40 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/18 02:04:55 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "libft.h"

typedef struct s_pipex
{
	char	**paths;
	char	**envp;
	char	**av;
	int		f1;
	int 	f2;
}	t_pipex;

void	get_paths(t_pipex *px);

#endif
