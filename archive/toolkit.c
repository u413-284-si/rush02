

int	is_same(char *str, char *to_find)
{
	int	j;
	int	same;

	j = 0;
	same = 1;
	while (to_find[j] && same == 1)
	{
		if (str[j] != to_find[j])
			same = 0;
		j++;
	}
	return (same);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{	
		if (str[i] == to_find[0])
		{
			if (is_same(&str[i], to_find))
				return (&str[i]);
		}
		i++;
	}
	return (0);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strlen(char *str)
{
	int	a;
	a = 0;
	while(*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			a++;
		str++;
	}
	return (a);
}

long unsigned int	ft_atoi(char *str)
{
	long unsigned int	i;
	long unsigned int	value;

	value = 0;
	i = 0;
	while (str[i] && str[i] >= 9 && str[i] <= 13)
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			return (5000000000);
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		value = 10 * value + (str[i] - 48);
		i++;
	}
	return (value);
}