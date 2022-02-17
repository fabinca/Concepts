/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:29:37 by cfabian           #+#    #+#             */
/*   Updated: 2022/02/17 15:05:56 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_args
{
	int				i;
	int				counter;
	pthread_mutex_t	lock;
}					t_args;

void	*add(void *args)
{
	int	i;
	int	j;

	j = ((t_args *)args)->i;
	usleep(3);
	i = 0;
	while (i++ < 10)
	{
		pthread_mutex_lock(&(((t_args *)args)->lock));
		((t_args *)args)->counter++;
		printf("Thread: %d, counter: %d\n", j, ((t_args *)args)->counter);
		pthread_mutex_unlock(&(((t_args *)args)->lock));
		usleep(6 / j);
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	tid[3];
	t_args		*args;

	args = malloc(sizeof(t_args));
	args->i = -1;
	args->counter = 0;
	while (++(args->i) < 3)
	{
		pthread_create(&(tid[args->i]), NULL, &add, (void *)args);
	}
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_join(tid[2], NULL);
	return (0);
}
