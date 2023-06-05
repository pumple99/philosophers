/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:47:37 by seunghoy          #+#    #+#             */
/*   Updated: 2023/06/05 16:16:02 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>

#include "../philo.h"
#include "../structure.h"

static void	info_value_init(int argc, char *argv[], t_info *info)
{
	info->end_flag = 0;
	info->count_complete_philo = 0;
	info->number_of_philosophers = fool_atoi(argv[1]);
	info->time_to_die = fool_atoi(argv[2]) * (long long)1000;
	info->time_to_eat = fool_atoi(argv[3]) * (long long)1000;
	info->time_to_sleep = fool_atoi(argv[4]) * (long long)1000;
	info->number_of_times_each_philosopher_must_eat = 0;
	if (argc == 5)
		return ;
	info->number_of_times_each_philosopher_must_eat = fool_atoi(argv[5]);
}

static int	malloc_init(t_info *info, t_philo **philos)
{
	int	idx;
	int	total;

	idx = -1;
	total = info->number_of_philosophers;
	info->fork = (t_status *)malloc(sizeof(t_status) * \
	info->number_of_philosophers);
	while (++idx < total)
	{
		if (idx % 2 == 0)
			info->fork[idx] = for_right_hand;
		else
			info->fork[idx] = for_left_hand;
	}
	info->fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* info->number_of_philosophers);
	*philos = (t_philo *)malloc(sizeof(t_philo) * info->number_of_philosophers);
	info->threads = (pthread_t *)malloc(sizeof(pthread_t) \
	* info->number_of_philosophers);
	if (info->fork && info->fork_mutex && *philos && info->threads)
		return (0);
	return (1);
}

static int	fork_mutex_init(t_info *info)
{
	int	total;
	int	idx;

	total = info->number_of_philosophers;
	idx = -1;
	while (++idx < total)
	{
		if (pthread_mutex_init(info->fork_mutex + idx, 0))
			return (destroy_mutex_at_init_err(info, idx));
	}
	return (0);
}

static void	philo_value_init(t_info *info, t_philo *philos)
{
	int	total;
	int	idx;

	info->start_time = get_time_us();
	total = info->number_of_philosophers;
	idx = -1;
	while (++idx < total)
	{
		philos[idx].philo_index = idx;
		philos[idx].last_eat_time = info->start_time;
		philos[idx].eat_count = 0;
		philos[idx].alive = 1;
		philos[idx].info = info;
	}
}

int	init_all(int argc, char *argv[], t_info *info, t_philo **philos)
{
	info_value_init(argc, argv, info);
	if (malloc_init(info, philos))
		return (5);
	if (pthread_mutex_init(&info->count_complete_philo_mutex, 0))
		return (4);
	if (pthread_mutex_init(&info->end_flag_mutex, 0))
		return (3);
	if (pthread_mutex_init(&info->message_mutex, 0))
		return (2);
	if (fork_mutex_init(info))
		return (1);
	philo_value_init(info, *philos);
	return (0);
}
