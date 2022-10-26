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

void	nubrhigh2(int count, char *str, int y, char *dict);
void	nubrhigh5(int count, char *str, int y, char *dict);
void	nubrhigh6(int count, char *str, int y, char *dict);
void	locate2(char *find, int count, char *dict);

void	comb_nubr_name2(int count, char *str, char *dict)
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
			locate2(find, count - 1, dict);
			count--;
			y++;
		}
		nubrhigh2(count, str, y, dict);
		y++;
		count--;
	}
}

void	nubrhigh2(int count, char *str, int y, char *dict)
{
	char	find[2];

	if (count == 1)
	{
		find[0] = str[y];
		find[1] = '\0';
		locate2(find, count, dict);
	}
	if (count == 2 || count == 5 || count == 8 || count == 11)
	{
		if (str[y] > '0')
		{
			find [0] = (str[y]);
			find [1] = '0';
		}
		locate2(find, count, dict);
	}
	if (count == 3 || count == 6 || count == 9 || count == 12)
	{
		find[0] = str[y];
		find[1] = '\0';
		locate2(find, count, dict);
		locate2("100", count, dict);
	}
	nubrhigh5(count, str, y, dict);
}

void	nubrhigh5(int count, char *str, int y, char *dict)
{
	char	find[2];

	if (count == 4)
	{
		if (str[y - 1] > '1' || str[y - 1] <= '0')
		{
			find[0] = str[y];
			find[1] = '\0';
			locate2(find, count, dict);
		}
		locate2("1000", count, dict);
	}
	if (count == 7)
	{
		if (str[y - 1] > '1' || str[y - 1] <= '0')
		{
			find[0] = str[y];
			find[1] = '\0';
			locate2(find, count, dict);
		}
		locate2("1000000", count, dict);
	}
	nubrhigh6(count, str, y, dict);
}

void	nubrhigh6(int count, char *str, int y, char *dict)
{
	char	find[2];

	if (count == 10)
	{
		if (str[y - 1] > '1' || str[y - 1] <= '0')
		{
			find[0] = str[y];
			find[1] = '\0';
			locate2(find, count, dict);
		}
		locate2("1000000000", count, dict);
	}
}
