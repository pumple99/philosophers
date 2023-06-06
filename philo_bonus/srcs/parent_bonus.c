/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:27:19 by seunghoy          #+#    #+#             */
/*   Updated: 2023/06/06 18:14:46 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/wait.h>

#include "../structure_bonus.h"
#include "../philo_bonus.h"
#include "../consts_bonus.h"

static void	if_fork_failed(t_philo *philo);

void	run_parent(t_philo *philo, int fork_fail)
{
	int	status;
	int	idx;

	if (fork_fail)
		return (if_fork_failed(philo));
	idx = -1;
	while (++idx < philo->number_of_philosophers)
		sem_wait(philo->complete_sem);
	idx = -1;
	while (++idx < philo->philo_index)
		kill(philo->childs[idx], SIGKILL);
	idx = -1;
	while (++idx < philo->philo_index)
		waitpid(philo->childs[idx], &status, 0);
	free_all(philo, 0);
}

static void	if_fork_failed(t_philo *philo)
{
	int	idx;
	int	status;

	idx = -1;
	while (++idx < philo->philo_index)
		kill(philo->childs[idx], SIGKILL);
	idx = -1;
	while (++idx < philo->philo_index)
		waitpid(philo->childs[idx], &status, 0);
	free_all(philo, 0);
	write_err(FORK_ERR);
}
