/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:20:39 by seunghoy          #+#    #+#             */
/*   Updated: 2023/06/04 20:45:54 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>

#include "../philo.h"
#include "../structure.h"
#include "../consts.h"

static int	get_fork(t_philo *philo, t_status stat);
static void	one_philo_complete(t_philo *philo);
static int	philo_eat(t_philo *philo);
static int	philo_sleep(t_philo *philo);

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (get_fork(philo, for_right_hand))
			break ;
		if (get_fork(philo, for_left_hand))
			break ;
		if (philo_eat(philo))
			break ;
		if (philo_sleep(philo))
			break ;
	}
	return (0);
}

static int	get_fork(t_philo *philo, t_status stat)
{
	int			fork_index;

	fork_index = (philo->philo_index + 1) % philo->info->number_of_philosophers;
	if (stat == for_right_hand)
		fork_index = philo->philo_index;
	while (1)
	{
		if (!is_alive(philo))
			return (1);
		pthread_mutex_lock(philo->info->fork_mutex + fork_index);
		if (philo->info->fork[fork_index] == stat)
		{
			philo->info->fork[fork_index] = stat + 2;
			pthread_mutex_unlock(philo->info->fork_mutex + fork_index);
			write_message(philo, GOT_FORK);
			return (0);
		}
		pthread_mutex_unlock(philo->info->fork_mutex + fork_index);
		usleep(1);
	}
	return (0);
}

static void	one_philo_complete(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->count_complete_philo_mutex);
	if (++(philo->info->count_complete_philo) == \
	philo->info->number_of_philosophers)
	{
		pthread_mutex_lock(&philo->info->end_flag_mutex);
		philo->info->end_flag = 1;
		pthread_mutex_unlock(&philo->info->end_flag_mutex);
	}
	pthread_mutex_unlock(&philo->info->count_complete_philo_mutex);
}

static int	philo_eat(t_philo *philo)
{
	long long	now;
	int			fork_index;

	now = write_message(philo, EATING);
	philo->eat_count += 1;
	if (philo->eat_count == \
	philo->info->number_of_times_each_philosopher_must_eat)
		one_philo_complete(philo);
	philo->last_eat_time = now;
	if (philo->info->time_to_die <= philo->info->time_to_eat)
	{
		optimize_sleep(now, philo->info->time_to_die);
		return (is_alive(philo), 1);
	}
	optimize_sleep(now, philo->info->time_to_eat);
	fork_index = (philo->philo_index + 1) % philo->info->number_of_philosophers;
	pthread_mutex_lock(philo->info->fork_mutex + fork_index);
	philo->info->fork[fork_index] = for_right_hand;
	pthread_mutex_unlock(philo->info->fork_mutex + fork_index);
	pthread_mutex_lock(philo->info->fork_mutex + philo->philo_index);
	philo->info->fork[philo->philo_index] = for_left_hand;
	pthread_mutex_unlock(philo->info->fork_mutex + philo->philo_index);
	return (0);
}

static int	philo_sleep(t_philo *philo)
{
	long long	now;
	long long	time_left;

	now = write_message(philo, SLEEPING);
	time_left = philo->info->time_to_die - (now - philo->last_eat_time);
	if (time_left <= philo->info->time_to_sleep)
	{
		if (time_left >= 0)
			optimize_sleep(now, time_left);
		return (is_alive(philo), 1);
	}
	optimize_sleep(now, philo->info->time_to_sleep);
	write_message(philo, THINKING);
	return (0);
}
