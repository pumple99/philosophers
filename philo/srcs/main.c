/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:08:01 by seunghoy          #+#    #+#             */
/*   Updated: 2023/05/18 19:57:37 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
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
}
