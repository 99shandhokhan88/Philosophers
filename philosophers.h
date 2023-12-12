/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:35:17 by vzashev           #+#    #+#             */
/*   Updated: 2023/12/12 14:47:06 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/types.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>

typedef struct s_philo
{
	int				philo_name;
	int				meals;
	int				is_eating;
	int				flag;
	u_int64_t		life_time;
	pthread_t		thread;
	pthread_mutex_t	lock;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	struct s_chef	*chef;
}	t_philo;

typedef struct s_chef
{
	int				num_philos;
	u_int64_t		die_time;
	u_int64_t		eat_time;
	u_int64_t		sleep_time;
	int				must_meals;
	u_int64_t		start;
	int				dead;
	int				end;
	pthread_t		*thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
	t_philo			*philo;
}	t_chef;

void		my_check(int argc);
int			my_atoi(const char *str);
int			my_error(char *str, t_chef *chef);
void		my_exit(t_chef *chef);
void		my_free(t_chef	*chef);
void		my_check_input(t_chef *table, int argc);
u_int64_t	my_time(void);
void		*the_boss(void *new_table);
int			my_usleep(u_int64_t time);
void		*philo_routine(void	*yeat);
void		*the_monitor(void *socrates);
void		has_died(t_philo *plato);
void		is_eating(t_philo *plato);
void		is_sleeping(t_philo *plato);
void		is_thinking(t_philo *plato);

#endif
