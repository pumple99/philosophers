/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:11:46 by seunghoy          #+#    #+#             */
/*   Updated: 2023/06/09 21:01:37 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	re;

	if (str == 0)
		return (0);
	re = 0;
	while (str[re])
		++re;
	return (re);
}

int	fool_atoi(char *str)
{
	int	val;

	val = 0;
	if (str[0] == '+')
		++str;
	while (*str)
	{
		val *= 10;
		val += (int)(*str - '0');
		++str;
	}
	return (val);
}

void	fool_itoa(char str[], int number)
{
	int	num;
	int	idx;

	num = number;
	idx = 0;
	while (num > 0)
	{
		num /= 10;
		++idx;
	}
	str[idx] = 0;
	while (--idx >= 0)
	{
		str[idx] = "0123456789"[number % 10];
		number /= 10;
	}
}

int	is_positive_int(char *str)
{
	int	i;

	if (str[0] == '+')
		++str;
	if (ft_strlen(str) == 0)
		return (0);
	if (str[0] == '0')
		return (0);
	i = -1;
	while (str[++i])
	{
		if (str[i] < '0' || '9' < str[i])
			return (0);
	}
	if (i > 9)
		return (0);
	return (1);
}
