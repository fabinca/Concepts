/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:14:30 by cfabian           #+#    #+#             */
/*   Updated: 2022/02/17 15:27:41 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int	main(void)
{
	int		pipe_fd[2];
	pid_t	pid;
	char	buf[100] = {0};

	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
	{
		printf("---Child process\n...\n");
		dprintf(pipe_fd[1], \
		"---This is written to fd %d in the child.\n", pipe_fd[1]);
	}
	else
	{
		wait(0);
		printf("Parent process\n...\n");
		read(pipe_fd[0], buf, 99);
		printf("Parent is reading from fd %d:\n", pipe_fd[0]);
		printf("%s", buf);
	}
	return (0);
}
