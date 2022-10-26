/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:20:37 by sqiu              #+#    #+#             */
/*   Updated: 2022/09/18 21:39:08 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find);
char	*ft_cut(char *str);
void	ft_putstr(char *str, int count);

void	locate2(char *find, int count, char *dict)
{
	int		fd;
	char	buf[9999];
	int		eof;
	char	*rest;

	eof = 1;
	fd = open(dict, O_RDONLY);
	while (eof != 0)
	{
		eof = read(fd, buf, 5000);
		if (eof == -1)
		{
			write(1, "Dict Error\n", 11);
		}
	}
	rest = ft_strstr(buf, find);
	if (rest == NULL)
	{
		write(1, "Dict Error\n", 11);
	}
	rest = ft_cut(rest);
	ft_putstr(rest, count);
	close(fd);
}
