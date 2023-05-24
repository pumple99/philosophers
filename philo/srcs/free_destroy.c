/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:55:33 by seunghoy          #+#    #+#             */
/*   Updated: 2023/05/24 17:43:34 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>

#include "structure.h"

static void	destroy_fork_mutex(t_info *info)
{
	int	idx;
	int	total;

	total = info->number_of_philosophers;
	idx = -1;
	while (++idx < total)
		pthread_mutex_destroy(info->fork_mutex + idx);
}

void	free_all(t_info *info, t_philo *philos, int error)
{
	if (error == 0)
		destroy_fork_mutex(info);
	if (error <= 1)
		pthread_mutex_destroy(&info->message_mutex);
	if (error <= 2)
		pthread_mutex_destroy(&info->end_flag_mutex);
	if (error <= 3)
		pthread_mutex_destroy(&info->count_complete_philo_mutex);
	free(philos);
	free(info->fork);
	free(info->fork_mutex);
	free(info->threads);
}

int	destroy_mutex_at_init_err(t_info *info, int success_num)
{
	int	idx;

	idx = -1;
	while (++idx < success_num)
		pthread_mutex_destroy(info->fork_mutex + idx);
	return (1);
}
