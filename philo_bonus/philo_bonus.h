/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:34:30 by seunghoy          #+#    #+#             */
/*   Updated: 2023/06/06 22:24:15 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "structure_bonus.h"

//parent_bonus.c
void		run_parent(t_philo *philo, int fork_fail);

//child_bonus.c
void		run_child(t_philo *philo);

//monitor_bonus.c
int			make_monitor(t_philo *philo);

//init_bonus.c
int			init_basic(int argc, char *argv[], t_philo **philo_ptr);

//free_bonus.c
void		free_all(t_philo *philo, int error);

//time_sleep_bonus.c
long long	get_time_us(void);
void		optimize_sleep(long long start, long long sleep_time);
long long	get_elapse_time(t_philo *philo, long long now);

//utils_bonus.c
int			ft_strlen(char *str);
int			is_positive_int(char *str);
int			fool_atoi(char *str);
void		fool_itoa(char str[], int number);

//err_bonus.c
int			write_err(char *str);

#endif
