/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 02:09:06 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/21 00:59:41 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	usage(void)
{
	write(2, "usage: ./pipex [file1] [cmd1] [cmd2] [file2]\n", 45);
	exit(EXIT_FAILURE);
}

void	terminate()
{
	if (errno == 0)
		write(2, "Error\n", 6);
	else
		perror("Error");
	exit(EXIT_FAILURE);
}

void	free_split(char **args, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(args[i++]);
	free(args);
}
