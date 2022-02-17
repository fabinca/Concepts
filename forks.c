/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:07:42 by cfabian           #+#    #+#             */
/*   Updated: 2022/02/17 10:58:06 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int	fd;

	printf("My program starts here\n");
	fd = open("file", O_CREAT | O_TRUNC | O_RDWR, 0644);
	perror("open");
	pid = fork();
	if (pid == 0) //this will only be executed in the child process
	{
		dup2(fd, STDOUT_FILENO); //stdout is replaced by the specified fd so output will be written to the specified file
		close(fd);
		execve("./example", argv, envp);
	}
	wait(0); //letting the parent process wait fo the child to terminate first: this is necessary to let the program exit cleanly. 
	perror("execve");
	printf("My program ends here\n");
	return (0);
}
