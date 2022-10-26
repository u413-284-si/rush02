/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:38:05 by sqiu              #+#    #+#             */
/*   Updated: 2022/09/17 18:48:04 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putstr(char *str);
int		master_core(char *nbr, int size, char *final);
int 	input_process(int ac, char **av, char *nbr, int *size);

int	main(int ac, char **av)
{
    char    *nbr;
    char	*output;
    int     size;

	nbr = malloc (32);
	output = malloc (200);
	if (input_process(ac, av, nbr, &size))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (master_core(nbr, size, output))
		return (0);
	ft_putstr(output);
	free(nbr);
	free(output);
	return (0);
}
