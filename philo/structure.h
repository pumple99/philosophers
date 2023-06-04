/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:52:07 by seunghoy          #+#    #+#             */
/*   Updated: 2023/06/04 15:08:05 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include <pthread.h>

typedef enum e_status
{
	for_right_hand = 1,
	for_left_hand = 2,
	right_hand_using = 3,
	left_hand_using = 4
}	t_status;

typedef struct s_info
{
	pthread_t		*threads;
	long long		start_time;
	int				number_of_philosophers;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	t_status		*fork;
	int				end_flag;
	int				count_complete_philo;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	message_mutex;
	pthread_mutex_t	end_flag_mutex;
	pthread_mutex_t	count_complete_philo_mutex;
}	t_info;

typedef struct s_philo
{
	int			philo_index;
	long long	last_eat_time;
	int			eat_count;
	int			alive;
	t_info		*info;
}	t_philo;

#endif