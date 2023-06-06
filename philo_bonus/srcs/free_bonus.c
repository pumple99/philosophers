/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:55:33 by seunghoy          #+#    #+#             */
/*   Updated: 2023/06/06 18:06:13 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../structure_bonus.h"
#include "../consts_bonus.h"

static void	close_unlink_sem(t_philo *philo);

void	free_all(t_philo *philo, int error)
{
	if (error <= 1)
	{
		close_unlink_sem(philo);
		free(philo->childs);
		free(philo->last_eat_sem);
		free(philo->philo_num);
	}
	if (error <= 2)
		free(philo);
}

static void	close_unlink_sem(t_philo *philo)
{
	int	idx;

	idx = -1;
	while (++idx < philo->number_of_philosophers)
	{
		sem_close(philo->last_eat_sem[idx]);
		sem_unlink(philo->philo_num[idx].in_char);
	}
	sem_close(philo->complete_sem);
	sem_close(philo->waiting_sem);
	sem_close(philo->fork_sem);
	sem_close(philo->message_sem);
	sem_unlink(COMPLETE_SEM_NAME);
	sem_unlink(WAITING_SEM_NAME);
	sem_unlink(FORK_SEM_NAME);
	sem_unlink(MESSAGE_SEM_NAME);
}
