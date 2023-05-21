/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:47:37 by seunghoy          #+#    #+#             */
/*   Updated: 2023/05/21 21:04:21 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>

int	init_all(int argc, char *argv[], t_common *info, t_philo *philos)
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_times_philo_must_eat;

	info->
}

void	free_all(t_common *info, t_philo *philos)
{
	free(philos);
	free(info->)
	pthread_mutex_destroy(&info->message_mutex);
	pthread_mutex_destroy(&info->end_flag_mutex);
	pthread_mutex_destroy(&info->count_complete_philo_mutex);
}
