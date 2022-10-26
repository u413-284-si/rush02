/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:38:05 by sqiu              #+#    #+#             */
/*   Updated: 2022/09/18 21:28:02 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	input_process(int ac, char **av);

int	main(int ac, char **av)
{
	if (input_process(ac, av))
		write(1, "Error\n", 6);
	return (0);
}
