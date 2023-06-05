/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:34:30 by seunghoy          #+#    #+#             */
/*   Updated: 2023/06/05 21:33:00 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

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

//err_bonus.c
int			write_err(char *str);

#endif
