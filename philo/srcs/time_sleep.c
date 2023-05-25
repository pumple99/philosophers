/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_sleep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:11:21 by seunghoy          #+#    #+#             */
/*   Updated: 2023/05/25 20:52:08 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>

#include "../structure.h"

long long	get_time_us(void)
{
	long long		time;
	struct timeval	tv;

	gettimeofday(&tv, 0);
	time = tv.tv_sec;
	time = time * 1000000 + tv.tv_usec;
	return (time);
}

void	optimize_sleep(int ms)
{
	long long	start_time;
	long long	us;

	start_time = get_time_us();
	us = (long long)ms * 1000;
	while (1)
	{
		usleep(1000);
		if (get_time_us() > start_time + us)
			break ;
	}
}

long long	get_elapse_time(t_philo *philo)
{
	long long	elapse_time;

	elapse_time = philo->info->start_time - get_time_us();
	elapse_time /= 1000;
	return (elapse_time);
}
