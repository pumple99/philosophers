/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:19:06 by seunghoy          #+#    #+#             */
/*   Updated: 2023/06/06 23:22:41 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#include "../structure_bonus.h"
#include "../philo_bonus.h"
#include "../consts_bonus.h"

static void	*routine(void *arg);
static void	simulation_end(t_philo *philo);

int	make_monitor(t_philo *philo)
{
	pthread_t	thread;
	if (pthread_create(&thread, 0, routine, (void *)philo))
		return (simulation_end(philo), 1);
	return (0);
}

static long long	get_time_left(t_philo *philo, long long now)
{
	long long	time_left;
	long long	time_elapse;
	long long	last_eat_time;

	sem_wait(philo->last_eat_sem[philo->philo_index]);
	last_eat_time = philo->last_eat_time;
	sem_post(philo->last_eat_sem[philo->philo_index]);
	time_elapse = now - last_eat_time;
	time_left = philo->time_to_die - time_elapse;
	return (time_left);
}

#include <unistd.h>
static void	*routine(void *arg)
{
	t_philo		*philo;
	long long	time_left;
	long long	now;

	philo = (t_philo *)arg;
	while (1)
	{
		now = get_time_us();
		time_left = get_time_left(philo, now);
		if (time_left < 0)
		{
			sem_wait(philo->message_sem);
			printf("%lld %d %s", get_elapse_time(philo, get_time_us()), \
			philo->philo_index + 1, DIED);
			simulation_end(philo);
		}
		// else
		// 	usleep(1);
		// 	// optimize_sleep(now, time_left);
	}
	return (0);
}

static void	simulation_end(t_philo *philo)
{
	int	idx;

	idx = -1;
	while (++idx < philo->number_of_philosophers)
		sem_post(philo->complete_sem);
}
