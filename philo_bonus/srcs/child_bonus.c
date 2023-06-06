/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:44:52 by seunghoy          #+#    #+#             */
/*   Updated: 2023/06/06 22:52:57 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <stdio.h>

#include "../structure_bonus.h"
#include "../consts_bonus.h"
#include "../philo_bonus.h"

static void	philo_fork_eat(t_philo *philo);
static void	write_message(t_philo *philo, char *str);
static void	philo_sleep_think(t_philo *philo);

void	run_child(t_philo *philo)
{
	if (make_monitor(philo))
		return ;
	while (1)
	{
		philo_fork_eat(philo);
		philo_sleep_think(philo);
	}
}

static void	philo_fork_eat(t_philo *philo)
{
	long long	now;

	sem_wait(philo->waiting_sem);
	sem_wait(philo->fork_sem);
	write_message(philo, GOT_FORK);
	sem_wait(philo->fork_sem);
	write_message(philo, GOT_FORK);
	sem_post(philo->waiting_sem);
	now = get_time_us();
	sem_wait(philo->last_eat_sem[philo->philo_index]);
	philo->last_eat_time = now;
	sem_post(philo->last_eat_sem[philo->philo_index]);
	write_message(philo, EATING);
	optimize_sleep(now, philo->time_to_eat);
	sem_post(philo->fork_sem);
	sem_post(philo->fork_sem);
	if (philo->number_of_times_each_philosopher_must_eat && \
	++philo->eat_count == philo->number_of_times_each_philosopher_must_eat)
		sem_post(philo->complete_sem);
}

static void	philo_sleep_think(t_philo *philo)
{
	long long	now;

	now = get_time_us();
	write_message(philo, SLEEPING);
	optimize_sleep(now, philo->time_to_sleep);
	write_message(philo, THINKING);
}

static void	write_message(t_philo *philo, char *str)
{
	long long	now;

	sem_wait(philo->message_sem);
	now = get_time_us();
	printf("%lld %d %s", get_elapse_time(philo, now), \
	philo->philo_index + 1, str);
	sem_post(philo->message_sem);
}