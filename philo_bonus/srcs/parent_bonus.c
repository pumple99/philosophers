/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:27:19 by seunghoy          #+#    #+#             */
/*   Updated: 2023/06/05 22:01:51 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/wait.h>

#include "../structure_bonus.h"
#include "../philo_bonus.h"

static void	when_fork_failed(t_philo *philo);

void	run_parent(t_philo *philo, int fork_fail)
{
	if (fork_fail)
		return (when_fork_failed(philo));
}

static void	when_fork_failed(t_philo *philo)
{
	int	idx;
	int	status;

	idx = -1;
	while (++idx < philo->philo_index)
	{
		kill(philo->childs[idx], SIGKILL);
		waitpid(philo->childs[idx], &status, 0);
	}
	free_all(philo, 0);
	write_err("Failed to create child precesses\n");
}
