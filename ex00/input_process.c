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
int					ft_strlen(char *str);
void				comb_nubr_name(int count, char *str);
void				comb_nubr_name2(int count, char *str, char *dict);
int					input_process2(char **av);

void	ft_newstr(char *str)
{
	int		i;
	char	nbr[500];
	int		size;

	i = 0;
	size = 0;
	while (str[i] && str[i] >= 9 && str[i] <= 13)
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nbr[size] = str[i];
		size++;
		i++;
	}
	comb_nubr_name(size, nbr);
}

void	ft_newstr2(char *dict, char *str)
{
	int		i;
	char	nbr[500];
	int		size;

	i = 0;
	size = 0;
	while (str[i] && str[i] >= 9 && str[i] <= 13)
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nbr[size] = str[i];
		size++;
		i++;
	}
	comb_nubr_name2(size, nbr, dict);
}

int	input_process(int ac, char **av)
{
	long unsigned int	retrn;
	int					size;

	if (ac == 2)
	{
		size = ft_strlen(av[1]);
		if (size > 10)
			return (1);
		retrn = ft_atoi(av[1]);
		if (retrn == 5000000000)
			return (1);
		else if (retrn <= 4294967295)
			ft_newstr(av[1]);
		else
			return (1);
	}
	else if (ac == 3)
		input_process2(av);
	else
		return (1);
	return (0);
}

int	input_process2(char **av)
{
	long unsigned int	retrn;
	int					size;

	size = ft_strlen(av[2]);
	if (size > 10)
		return (1);
	retrn = ft_atoi(av[2]);
	if (retrn == 5000000000)
		return (1);
	else if (retrn <= 4294967295)
		ft_newstr2(av[1], av[2]);
	else
		return (1);
	return (0);
}
