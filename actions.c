/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <pcarmeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:09:25 by pcarmeli          #+#    #+#             */
/*   Updated: 2022/01/13 16:02:29 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eating(t_philosoph *philo)
{
	print_msg(philo, get_time(philo->start_time), "is eating");
	++philo->count_eat;
	philo->life = get_time(0);
	usleep_ch(philo->eat_time);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_sleeping(t_philosoph *philo)
{
	print_msg(philo, get_time(philo->start_time), "is sleeping");
	usleep_ch(philo->sleep_time);
}

void	philo_thinking(t_philosoph *philo)
{
	print_msg(philo, get_time(philo->start_time), "is thinking");
}
