/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <pcarmeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:17:08 by pcarmeli          #+#    #+#             */
/*   Updated: 2022/01/13 16:26:25 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_philosoph *philo, size_t time, char *msg)
{
	pthread_mutex_lock(&philo->global->checking);
	printf("%zu Philo №%d: %s\n", time, philo->index, msg);
	if (!philo->is_dead)
		pthread_mutex_unlock(&philo->global->checking);
}

void	philo_takes_fork(t_philosoph *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_msg(philo, get_time(philo->start_time), "has taken a LEFT fork");
	pthread_mutex_lock(philo->right_fork);
	print_msg(philo, get_time(philo->start_time), "has taken a RIGHT fork");
}

void	*ft_philo_actions(void *philo)
{
	t_philosoph	*philosoph;

	philosoph = (t_philosoph *)philo;
	if (philosoph->index % 2 == 0)
		usleep_ch(philosoph->eat_time / 2);
	while (1)
	{
		philo_takes_fork(philosoph);
		philo_eating(philosoph);
		philo_sleeping(philosoph);
		philo_thinking(philosoph);
	}
}

void	ft_start(t_global *global)
{
	pthread_t	*mas_of_philo_ids;
	int			i;

	global->mas_of_forks = malloc(sizeof(pthread_mutex_t) * global->philo_nmbr);
	global->mas_of_philos = malloc(sizeof(t_philosoph) * global->philo_nmbr);
	mas_of_philo_ids = malloc(sizeof(pthread_t) * global->philo_nmbr);
	i = 0;
	while (i < global->philo_nmbr)
	{
		pthread_mutex_init(&global->mas_of_forks[i], NULL);
		++i;
	}
	i = 0;
	pthread_mutex_init(&global->checking, NULL);
	while (i < global->philo_nmbr)
	{
		ft_philo_param(global, i, mas_of_philo_ids);
		global->mas_of_philos[i].index = i;
		pthread_create(&mas_of_philo_ids[i], NULL, \
		ft_philo_actions, (void *)&global->mas_of_philos[i]);
		++i;
	}
	ft_big_brother (global, mas_of_philo_ids);
}

int	main(int argc, char **argv)
{
	t_global	*global;

	global = malloc(sizeof(t_global));
	global->start_time = get_time(0);
	if (argc > 6 || argc < 5)
		return (ft_error("There are should be 5 or 6 args"));
	if (ft_checker(argc, argv) == 1)
		return (ft_error("You should write numbers"));
	ft_init_args(global, argv, argc);
	ft_start(global);
	free(global);
	return (0);
}
