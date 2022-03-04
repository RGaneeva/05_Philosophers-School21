/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <pcarmeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:17:15 by pcarmeli          #+#    #+#             */
/*   Updated: 2022/01/13 16:26:58 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	death_cheking(t_global *global, int i)
{
	if (global->mas_of_philos[i].count_eat >= global->times_to_eat \
	&& global->times_to_eat != -1)
		++global->tot_time_eating;
	if (global->die_time < get_time(global->mas_of_philos[i].life))
	{
		global->mas_of_philos[i].is_dead = 1;
		print_msg(&global->mas_of_philos[i], \
		get_time(global->start_time), "is died :(");
		return (0);
	}
	return (1);
}

void	*monitoring(void *val)
{
	t_global	*global;
	int			i;

	global = (t_global *)val;
	while (1)
	{
		i = -1;
		global->tot_time_eating = 0;
		while (++i < global->philo_nmbr)
			if (death_cheking(global, i) == 0)
				return (NULL);
		if (global->tot_time_eating == global->philo_nmbr)
		{
			pthread_mutex_lock(&global->checking);
			return (NULL);
		}
	}
}
