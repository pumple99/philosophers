/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:42:43 by seunghoy          #+#    #+#             */
/*   Updated: 2023/06/05 20:03:26 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_BONUS_H
# define STRUCTURE_BONUS_H

# include <unistd.h>
# include <semaphore.h>

typedef struct s_philo
{
	int			philo_index;
	long long	start_time;
	long long	last_eat_time;
	int			eat_count;
	int			number_of_philosophers;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	int			number_of_times_each_philosopher_must_eat;
	pid_t		*childs;
	sem_t		*message_sem;
	sem_t		*fork_sem;
	sem_t		*waiting_sem;
	sem_t		*complete_sem;
}	t_philo;

#endif
