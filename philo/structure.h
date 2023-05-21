/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:52:07 by seunghoy          #+#    #+#             */
/*   Updated: 2023/05/21 18:17:09 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

#include <pthread.h>

typedef struct s_common
{
	int				*fork;
	int				end_flag;
	int				count_complete_philo;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	message_mutex;
	pthread_mutex_t	end_flag_mutex;
	pthread_mutex_t	count_complete_philo_mutex;
}	t_common;

typedef struct s_philo
{
	long long	start_time;
	int			number_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_times_each_philosopher_must_eat;
	int			philo_index;
	long long	last_eat_time;
	int			eat_count;
	t_common	*common_info;
}	t_philo;

#endif