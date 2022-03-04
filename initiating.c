/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiating.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <pcarmeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:16:59 by pcarmeli          #+#    #+#             */
/*   Updated: 2022/01/13 16:24:21 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char const *str)
{
	int	i;
	int	is_neg;
	int	res;

	if (!str)
		return (0);
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		is_neg = -1;
	is_neg = 1;
	if (is_neg == -1 || str[i] == '+')
		i++;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	return (res * is_neg);
}

void	ft_init_args(t_global *global, char **argv, int argc)
{
	global->philo_nmbr = ft_atoi(argv[1]);
	global->die_time = ft_atoi(argv[2]);
	global->eat_time = ft_atoi(argv[3]);
	global->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		global -> times_to_eat = ft_atoi(argv[5]);
	else
		global->times_to_eat = -1;
}

void	ft_philo_param(t_global *global, int index, pthread_t *threads)
{
	global->mas_of_philos[index].die_time = global->die_time;
	global->mas_of_philos[index].eat_time = global->eat_time;
	global->mas_of_philos[index].sleep_time = global->sleep_time;
	global->mas_of_philos[index].start_time = global->start_time;
	global->mas_of_philos[index].index = index;
	global->mas_of_philos[index].is_dead = 0;
	global->mas_of_philos[index].life = get_time(0);
	global->mas_of_philos[index].left_fork = \
			&global->mas_of_forks[index];
	global->mas_of_philos[index].right_fork = \
			&global->mas_of_forks[(index + 1) % global->philo_nmbr];
	global->mas_of_philos[index].global = global;
	global->mas_of_philos[index].thread = threads[index];
	global->mas_of_philos[index].count_eat = 0;
}

void	ft_big_brother(t_global *global, pthread_t *mas_of_philo_ids)
{
	pthread_t	check_death;

	pthread_create(&check_death, NULL, monitoring, global);
	pthread_join(check_death, NULL);
	pthread_detach(check_death);
	free(global->mas_of_forks);
	free(global->mas_of_philos);
	free(mas_of_philo_ids);
}
