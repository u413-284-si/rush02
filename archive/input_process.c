/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:21:24 by vstockma          #+#    #+#             */
/*   Updated: 2022/09/17 12:21:26 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

long unsigned int	ft_atoi(char *str);
int	ft_strlen(char *str);

void 	ft_newstr(char *str, char *nbr)
{
	int	i;
	int	a;
	//char	*ptr;
	
	i = 0;
	a = 0;
	//ptr = malloc(*size * sizeof(char));
	while (str[i] && str[i] >= 9 && str[i] <= 13)
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nbr[a] = str[i];
		a++;
		i++;
	}
	//return (ptr);
}

int input_process(int ac, char **av, char *nbr, int *size)
{
	long unsigned int	retrn;
	
	if (ac == 2)
	{
		*size = ft_strlen(av[1]);
		if (*size > 10)
			return (1);
		retrn = ft_atoi(av[1]);
		if (retrn == 5000000000)
			return (1);
		else if (retrn < 4294967295)
			ft_newstr(av[1], nbr);
		else
			return (1);
	}
	else if (ac == 3)
	{
		*size = ft_strlen(av[2]);
		if (*size > 10)
			return (1);
		retrn = ft_atoi(av[2]);
		
		if (retrn == 5000000000)
			return (1);
		else if (retrn < 4294967295)
			ft_newstr(av[2], nbr);
		else
			return (1);
	}
	else
		return (1);
	return (0);
}
