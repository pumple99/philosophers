/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:08:01 by seunghoy          #+#    #+#             */
/*   Updated: 2023/06/05 21:14:01 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <unistd.h>
#include <sys/wait.h>

#include "../philo_bonus.h"
#include "../structure_bonus.h"

static int	check_input(int argc, char *argv[]);
static void	run(t_philo *philo);

int	main(int argc, char *argv[])
{
	t_philo		*philo;
	int			error;

	if (check_input(argc, argv))
		return (1);
	error = init_basic(argc, argv, &philo);
	if (!error)
		run(philo);
	free_all(philo, error);
}

static int	check_input(int argc, char *argv[])
{
	int	i;

	if (argc < 5 || argc > 6)
		return (write_err("Argument number error!"));
	i = 0;
	while (++i < argc)
	{
		if (!is_positive_int(argv[i]))
			return (write_err("Not positive or too big integer"));
	}
	return (0);
}

static void	run(t_philo *philo)
{
	int		idx;
	int		idx2;
	int		fork_fail;
	pid_t	child;

	child = 1;
	fork_fail = 0;
	while (child != 0 && ++philo->philo_index < philo->number_of_philosophers)
	{
		child = fork();
		if (child == -1)
		{
			fork_fail = 1;
			break ;
		}
		else if (child != 0)
			philo->childs[philo->philo_index] = child;
	}
	if (child == 0)
		return (run_child(philo));
}
