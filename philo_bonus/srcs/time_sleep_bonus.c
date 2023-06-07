/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_sleep_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:11:21 by seunghoy          #+#    #+#             */
/*   Updated: 2023/06/07 18:05:52 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>

#include "../structure_bonus.h"

long long	get_time_us(void)
{
	long long		time;
	struct timeval	tv;

	gettimeofday(&tv, 0);
	time = tv.tv_sec * 1000000 + tv.tv_usec;
	return (time);
}

void	optimize_sleep(long long start, long long sleep_time)
{
	if (sleep_time > 10000)
		usleep(sleep_time - 5000);
	while (1)
	{
		if (get_time_us() > start + sleep_time)
			break ;
		usleep(1);
	}
}

long long	get_elapse_time(t_philo *philo, long long now)
{
	long long	elapse_time;

	elapse_time = now - philo->start_time;
	elapse_time /= 1000;
	return (elapse_time);
}
