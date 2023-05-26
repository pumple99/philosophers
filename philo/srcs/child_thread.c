/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:20:39 by seunghoy          #+#    #+#             */
/*   Updated: 2023/05/26 21:54:03 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>

#include "../philo.h"
#include "../structure.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (get_right_fork())
			break ;
		if (get_left_fork())
			break ;
		if (eat())
			break ;
	}
	return (0);
}

static int	get_right_fork()
{
	
}

int	is_alive(t_philo *philo)
{
	if (get_time_us() <= philo->last_eat_time + \
	philo->info->time_to_die * 1000 && !get_end_flag_value(philo))
		return (1);
	pthread_mutex_lock(&philo->info->end_flag_mutex);
	philo->info->end_flag = 1;
	pthread_mutex_unlock(&philo->info->end_flag_mutex);
	return (0);
}
