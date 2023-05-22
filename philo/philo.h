/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:15:23 by seunghoy          #+#    #+#             */
/*   Updated: 2023/05/22 17:59:57 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//init.c
int		init_all(int argc, char *argv[], t_info *info, t_philo **philos);

//free_destroy.c
void	free_all(t_common *info, t_philo *philos, int error);
int		destroy_mutex_at_init_err(t_info *info, int success_num);

//utils.c
int		ft_strlen(char *str);
int		is_positive_int(char *str);
int		fool_atoi(char *str);

//err.c
int		write_err(char *str);

#endif
