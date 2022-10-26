/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:20:37 by sqiu              #+#    #+#             */
/*   Updated: 2022/09/18 21:41:31 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find);
char	*ft_cut(char *str);

void	ft_putstr(char *str, int count)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	if (count > 1)
		write(1, " ", 1);
	else if (count == 1)
		write(1, "\n", 1);
}

void	locate(char *find, int count)
{
	int		fd;
	char	buf[9999];
	int		eof;
	char	*rest;

	eof = 1;
	fd = open("numbers.dict", O_RDONLY);
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

void	extract(char *str, char *result, int i)
{
	int		j;

	j = 0;
	while (str[i] != '\n'
		&& (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	i -= 1;
	while (str[i] == ' ')
	{
		i++;
		while (str[i] > 32 && str[i] <= 126)
			result[j++] = str[i++];
		if ((str[i - 1] > 32 && str[i - 1] <= 126) && str[i] == ' ')
			result[j++] = ' ';
	}
}

char	*ft_cut(char *str)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *) malloc (200);
	while (str[i] != '\n')
	{
		if (str[i] == ':')
		{
			i++;
			extract(str, result, i);
			return (result);
		}
		i++;
	}
	free(result);
	return (0);
}
