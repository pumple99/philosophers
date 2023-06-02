/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_thread_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:47:24 by seunghoy          #+#    #+#             */
/*   Updated: 2023/06/02 21:48:11 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

#include "../philo.h"
#include "../structure.h"
#include "../consts.h"

int	get_end_flag_value(t_philo *philo)
{
	int	val;

	pthread_mutex_lock(&philo->info->end_flag_mutex);
	val = philo->info->end_flag;
	pthread_mutex_unlock(&philo->info->end_flag_mutex);
	return (val);
}

void	write_message(t_philo *philo, char *str, long long now)
{
	long long	elapse_time;

	elapse_time = get_elapse_time(philo, now);
	pthread_mutex_lock(&philo->info->message_mutex);
	if (get_end_flag_value(philo))
	{
		pthread_mutex_unlock(&philo->info->message_mutex);
		return ;
	}
	printf("%lld %d %s", elapse_time, philo->philo_index + 1, str);
	pthread_mutex_unlock(&philo->info->message_mutex);
}

int	is_alive(t_philo *philo)
{
	long long	now;

	if (get_end_flag_value(philo))
		return (0);
	now = get_time_us();
	if (now <= philo->last_eat_time + \
	philo->info->time_to_die)
		return (1);
	pthread_mutex_lock(&philo->info->message_mutex);
	pthread_mutex_lock(&philo->info->end_flag_mutex);
	if (!philo->info->end_flag)
	{
		philo->info->end_flag = 1;
		printf("%lld %d %s", get_elapse_time(philo, now), \
		philo->philo_index + 1, DIED);
	}
	pthread_mutex_unlock(&philo->info->end_flag_mutex);
	pthread_mutex_unlock(&philo->info->message_mutex);
	return (0);
}
