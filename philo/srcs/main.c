/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:08:01 by seunghoy          #+#    #+#             */
/*   Updated: 2023/05/22 23:34:41 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

#include "philo.h"
#include "structure.h"

int	check_input(int argc, char *argv[])
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

int	main(int argc, char *argv[])
{
	t_info	info;
	t_philo	*philos;
	int		error;

	if (check_input(argc, argv))
		return (1);
	error = init_all(argc, argv, &info, &philos);
	// if (!error)
	// 	run(philos);
	free_all(&info, philos, error);
}
