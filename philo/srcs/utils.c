/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:11:46 by seunghoy          #+#    #+#             */
/*   Updated: 2023/05/21 15:46:26 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

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

int	is_positive_int(char *str)
{
	int	i;

	i = -1;
	if (str[0] == '+')
		++str;
	if (str[0] == '0')
		return (0);
	while (str[++i])
	{
		if (str[i] < '0' || '9' < str[i])
			return (0);
	}
	if (i > 9)
		return (0);
	return (1);
}

long long	get_time(void)
{
	long long		time;
	struct timeval	tv;

	gettimeofday(&tv, 0);
	time = tv.tv_sec;
	time = time * 1000 + (tv.tv_usec / 1000);
	return (time);
}
