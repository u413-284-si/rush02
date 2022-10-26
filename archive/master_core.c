/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:21:24 by sqiu              #+#    #+#             */
/*   Updated: 2022/09/17 19:21:28 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find);
int		ft_cut_len(char *str);
char	*ft_cut(char *str);
int	str_len(char *str);
char	*ft_strcat(char *dest, char *src);

char *locate(char *find, int *stop)
{
	int	fd;
	char	buf[9999];
	int	eof;
	char *rest;

	eof = 1;
	*stop = 0;
	fd = open("numbers.dict", O_RDONLY);
	while (eof != 0)
	{
		eof = read(fd, buf, 5000);
		if (eof == -1)
		{
			write(1, "Dict Error\n", 11);
			*stop = 1;
		}
	}
	//printf("%s\n", find);
	rest = ft_strstr(buf, find);
	//printf("%s\n", rest);
	if (rest == NULL)
		{
			write(1, "Dic Error\n", 11);
			*stop = 1;
		}
	rest = ft_cut(rest);
	//printf("%s\n", rest);
	close(fd);
	return (rest);
}

void	nubrhigh(int count, char *rest, int *stop)
{
	if (count == 4)
		rest = locate("1000", stop);
	if (count == 7)
		rest = locate("1000000", stop);
	if (count == 10 && rest)
		rest = locate("1000000000", stop);
}

char	*comb_nubr_name(int count, char *str, char *rest, int *stop, int y)
{
	char find[2];
	char digit[1];

	if (str[y] < '2' && (count == 2 || count == 5 || count == 8 || count == 11))
	{
		if (str[y] != '0')
			find [0] = (str[y]);
		find [1] = (str[y + 1]);
		rest = locate(find, stop);
	}
	if (count == 1 || count == 4 || count == 7 || count == 10)
	{
		if (str[y] == '0' && y == 0)
			digit[0] = str[y];
		if (str[y] != '0')
		{	
			digit[0] = str[y];
		}
		rest = locate(digit, stop);
		printf("%s\n", rest);
	} 
	if (count == 2 || count == 5 || count == 8 || count == 11)
	{
		if (str[y] > '0')
		{
			find [0] = (str[y]);
			find [1] = '0';
		}
		rest = locate(find, stop);
		//printf("%s\n", rest);
	}
	if (count == 3 || count == 6 || count == 9 || count == 12)
	{
		digit[0] = str[y];
		rest = locate(digit, stop);
		rest = locate("100", stop);
	}
	nubrhigh(count, rest, stop);
}

// char	*ft_mall(int counter)
// {
// 	char	*ptr;
// 	int	size;
	
// 	size = size + counter + 1;
// 	ptr = malloc(size * sizeof(char));

// 	return (ptr);
// }

int	master_core(char *nbr, int size, char *final)
{
	char	precut[100];
	char	cut_str[50];
	char	postcut[50];
	int		fin_str_size;
	int 	stop;
	int		temp;
	int y;
	
	y = 0;
	fin_str_size = 0;
	temp = size;
	while (size > 0)
	{
		//printf("%d %d\n", size, y);
		postcut = comb_nubr_name(size, nbr, precut, &stop, y);
		printf("%s\n", precut);
		fin_str_size = fin_str_size + str_len(postcut) + 1;
		size--;
		y++;
	}
	final = malloc(fin_str_size * sizeof(char));
	y = 0;
	while (temp > 0)
	{
		postcut = comb_nubr_name(temp, nbr, cut_str, &stop, y);
		ft_strcat(final, postcut);
		temp--;
		y++;
	}
	return (stop);
}
