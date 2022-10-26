/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:55:46 by sqiu              #+#    #+#             */
/*   Updated: 2022/09/17 21:55:50 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

char	*ft_strcat(char *dest, char *src)
{
	int	isrc;
	int count;

	count = 0;
	isrc = 0;
	while (dest[count] != '\0')
		count++;
	while (src[isrc] != '\0')
	{
		dest[count + isrc] = src[isrc];
		isrc++;
	}
	dest[count + isrc] = '\0';
	return (dest);
}

int	ft_cut_len(char *str)
{
	int	i;
	int	counter;
	
	counter = 0;
	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == ':')
		{
			i++;
			while (str[i] != '\n' && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
				i++;
			while (str[i] > 32 && str[i] <= 126)
			{
				while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
					i++;
				i++;
				counter++;
			}
		}	
		i++;
		
	}
	return (counter);
}

char	*ft_cut(char *str)
{
	char	*result;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	result = (char *) malloc (200);
	while (str[i] != '\n')
	{
		if (str[i] == ':')
		{
			i++;
			while (str[i] != '\n' && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
				i++;
			while (str[i] > 32 && str[i] <= 126)
			{
				while (str[i] == ' ')
					i++;
				result[j] = str[i];
				j++;
				i++;
			}
			return (result);
		}	
		i++;
		
	}
	return (0);
}
