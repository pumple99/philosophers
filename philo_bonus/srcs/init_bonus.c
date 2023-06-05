/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:47:37 by seunghoy          #+#    #+#             */
/*   Updated: 2023/06/05 21:19:16 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../philo_bonus.h"
#include "../structure_bonus.h"
#include "../consts_bonus.h"

static int	malloc_init(int argc, char *argv[], t_philo **philo_ptr);
static void	basic_value_init(int argc, char *argv, t_philo *philo);
static int	sem_init(t_philo *philo);

int	init_basic(int argc, char *argv[], t_philo **philo_ptr)
{
	int	err_malloc_init;

	err_malloc_init = malloc_init(argc, argv, philo_ptr);
	if (err_malloc_init)
		return (err_malloc_init);
	if (sem_init(*philo_ptr))
		return (1);
	(*philo_ptr)->start_time = get_time_us();
	(*philo_ptr)->last_eat_time = (*philo_ptr)->start_time;
	return (0);
}

static int	malloc_init(int argc, char *argv[], t_philo **philo_ptr)
{
	*philo_ptr = (t_philo *)malloc(sizeof(t_philo));
	if (*philo_ptr == 0)
		return (3);
	basic_value_init(argc, argv, *philo_ptr);
	(*philo_ptr)->childs = (pid_t *)malloc(sizeof(pid_t) * \
	(*philo_ptr)->number_of_philosophers);
	if ((*philo_ptr)->childs == 0)
		return (2);
	return (0);
}

static void	basic_value_init(int argc, char *argv, t_philo *philo)
{
	philo->philo_index = -1;
	philo->eat_count = 0;
	philo->number_of_philosophers = fool_atoi(argv[1]);
	philo->time_to_die = fool_atoi(argv[2]) * (long long)1000;
	philo->time_to_eat = fool_atoi(argv[3]) * (long long)1000;
	philo->time_to_sleep = fool_atoi(argv[4]) * (long long)1000;
	philo->number_of_times_each_philosopher_must_eat = 0;
	if (argc == 5)
		return ;
	philo->number_of_times_each_philosopher_must_eat = fool_atoi(argv[5]);
}

static int	sem_init(t_philo *philo)
{
	philo->message_sem = sem_open(MESSAGE_SEM_NAME, O_CREAT | O_EXCL, 0644, 1);
	philo->fork_sem = sem_open(FORK_SEM_NAME, O_CREAT | O_EXCL, \
	0644, philo->number_of_philosophers);
	philo->waiting_sem = sem_open(WAITING_SEM_NAME, O_CREAT | O_EXCL, 0644, 1);
	philo->complete_sem = sem_open(COMPLETE_SEM_NAME, O_CREAT | O_EXCL, \
	0644, philo->number_of_philosophers);
	if (philo->message_sem == SEM_FAILED || philo->fork_sem == SEM_FAILED || \
	philo->waiting_sem == SEM_FAILED || philo->complete_sem == SEM_FAILED)
		return (1);
	return (0);
}

