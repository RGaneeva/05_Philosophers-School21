/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <pcarmeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:09:59 by pcarmeli          #+#    #+#             */
/*   Updated: 2022/01/13 16:22:27 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

ssize_t	get_time(ssize_t begin_time)
{
	struct timeval	t1;

	gettimeofday(&t1, NULL);
	return ((t1.tv_sec * 1000 + t1.tv_usec / 1000) - begin_time);
}

void	usleep_ch(ssize_t time)
{
	struct timeval	t1;
	ssize_t			timing;

	gettimeofday(&t1, NULL);
	timing = t1.tv_sec * 1000 + t1.tv_usec / 1000;
	while (time > (t1.tv_sec * 1000 + t1.tv_usec / 1000) - timing)
	{
		gettimeofday(&t1, NULL);
		usleep(100);
	}
}

int	argv_checking(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		++i;
	}
	return (0);
}

int	ft_error(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i++], 1);
		i++;
	}
	write(1, "\n", 1);
	return (-1);
}

int	ft_checker(int argc, char **argv)
{
	int	x;

	x = 1;
	while (x < argc)
	{
		if (argv_checking(argv[x]) != 0)
			return (-1);
		++x;
	}
	return (0);
}
