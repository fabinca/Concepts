/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabian <cfabian@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:34:05 by cfabian           #+#    #+#             */
/*   Updated: 2022/02/17 10:40:16 by cfabian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(int argc, char **argv)
{
	printf("----Starting example Program \n");
	printf("----Printing all my arguments: \n");
	while (*argv)
	{
		printf("----%s \n", *argv);
		argv++;
	}
	printf("----Ending example Program \n");
	return (0);
}
