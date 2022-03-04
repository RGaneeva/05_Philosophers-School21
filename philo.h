/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <pcarmeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:17:35 by pcarmeli          #+#    #+#             */
/*   Updated: 2022/01/13 16:31:43 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_global	t_global;

typedef struct s_philosoph
{
	int				index;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				is_dead;
	int				count_eat;
	t_global		*global;
	ssize_t			life;
	ssize_t			start_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philosoph;

typedef struct s_global
{
	int				philo_nmbr;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				times_to_eat;
	int				tot_time_eating;
	ssize_t			start_time;
	pthread_mutex_t	*mas_of_forks;
	pthread_mutex_t	checking;
	t_philosoph		*mas_of_philos;
}	t_global;

void	ft_start(t_global *global);
void	*ft_philo_actions(void *philo);
void	philo_takes_fork(t_philosoph *philo);
void	print_msg(t_philosoph *philo, size_t time, char *msg);
void	ft_philo_param(t_global *global, int index, pthread_t *threads);
void	ft_init_args(t_global *global, char **argv, int argc);
int		ft_atoi(char const *str);
void	ft_dop(t_global *global, pthread_t *mas_of_philo_ids);
void	ft_big_brother(t_global *global, pthread_t *mas_of_philo_ids);
int		ft_checker(int argc, char **argv);
int		ft_error(char *str);
int		argv_checking(char *str);
void	usleep_ch(ssize_t time);
ssize_t	get_time(ssize_t begin_time);
void	*monitoring(void *val);
int		death_cheking(t_global *global, int i);
void	philo_eating(t_philosoph *philo);
void	philo_sleeping(t_philosoph *philo);
void	philo_thinking(t_philosoph *philo);

#endif
