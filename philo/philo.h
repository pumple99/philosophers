/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:15:23 by seunghoy          #+#    #+#             */
/*   Updated: 2023/06/02 21:45:36 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "structure.h"

//child_thread.c
void		*routine(void *arg);

//child_thread_utils.c
int			get_end_flag_value(t_philo *philo);
void		write_message(t_philo *philo, char *str, long long now);
int			is_alive(t_philo *philo);

//time_sleep.c
long long	get_time_us(void);
void		optimize_sleep(long long start, long long sleep_time);
long long	get_elapse_time(t_philo *philo, long long now);

//init.c
int			init_all(int argc, char *argv[], t_info *info, t_philo **philos);

//free_destroy.c
void		free_all(t_info *info, t_philo *philos, int error);
int			destroy_mutex_at_init_err(t_info *info, int success_num);

//utils.c
int			ft_strlen(char *str);
int			is_positive_int(char *str);
int			fool_atoi(char *str);

//err.c
int			write_err(char *str);

#endif
