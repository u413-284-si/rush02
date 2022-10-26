/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb_nubr_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:02:36 by secker            #+#    #+#             */
/*   Updated: 2022/09/17 19:38:30 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	nubrhigh(int count, char *str, int y);
void	nubrhigh3(int count, char *str, int y);
void	nubrhigh4(int count, char *str, int y);
void	locate(char *find, int count);

void	comb_nubr_name(int count, char *str)
{
	int		y;
	char	find[2];

	y = 0;
	while (count > 0)
	{
		if (str[y] < '2'
			&& (count == 2 || count == 5 || count == 8 || count == 11))
		{
			if (str[y] != '0')
				find [0] = (str[y]);
			find[1] = (str[y + 1]);
			locate(find, count - 1);
			count--;
			y++;
		}
		nubrhigh(count, str, y);
		y++;
		count--;
	}
}

void	nubrhigh(int count, char *str, int y)
{
	char	find[2];

	if (count == 1)
	{
		find[0] = str[y];
		find[1] = '\0';
		locate(find, count);
	}
	if (count == 2 || count == 5 || count == 8 || count == 11)
	{
		if (str[y] > '0')
		{
			find [0] = (str[y]);
			find [1] = '0';
		}
		locate(find, count);
	}
	if (count == 3 || count == 6 || count == 9 || count == 12)
	{
		find[0] = str[y];
		find[1] = '\0';
		locate(find, count);
		locate("100", count);
	}
	nubrhigh3(count, str, y);
}

void	nubrhigh3(int count, char *str, int y)
{
	char	find[2];

	if (count == 4)
	{
		if (str[y - 1] > '1' || str[y - 1] <= '0')
		{
			find[0] = str[y];
			find[1] = '\0';
			locate(find, count);
		}
		locate("1000", count);
	}
	if (count == 7)
	{
		if (str[y - 1] > '1' || str[y - 1] <= '0')
		{
			find[0] = str[y];
			find[1] = '\0';
			locate(find, count);
		}
		locate("1000000", count);
	}
	nubrhigh4(count, str, y);
}

void	nubrhigh4(int count, char *str, int y)
{
	char	find[2];	

	if (count == 10)
	{
		if (str[y - 1] > '1' || str[y - 1] <= '0')
		{
			find[0] = str[y];
			find[1] = '\0';
			locate(find, count);
		}
		locate("1000000000", count);
	}
}
