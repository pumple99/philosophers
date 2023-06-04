/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:08:01 by seunghoy          #+#    #+#             */
/*   Updated: 2023/06/04 15:07:35 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

#include "../philo.h"
#include "../structure.h"

static int	check_input(int argc, char *argv[]);
static void	run(t_info *info, t_philo *philos);

int	main(int argc, char *argv[])
{
	t_info		info;
	t_philo		*philos;
	int			error;

	if (check_input(argc, argv))
		return (1);
	error = init_all(argc, argv, &info, &philos);
	if (!error)
		run(&info, philos);
	free_all(&info, philos, error);
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

static void	run(t_info *info, t_philo *philos)
{
	int	idx;
	int	idx2;
	int	total;

	total = info->number_of_philosophers;
	idx = -1;
	while (++idx < total)
	{
		if (pthread_create(info->threads + idx, 0, routine, philos + idx))
		{
			pthread_mutex_lock(&info->end_flag_mutex);
			info->end_flag = 1;
			pthread_mutex_unlock(&info->end_flag_mutex);
			break ;
		}
	}
	idx2 = -1;
	while (++idx2 < idx)
		pthread_join(info->threads[idx2], 0);
}
