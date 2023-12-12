/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:31:49 by vzashev           #+#    #+#             */
/*   Updated: 2023/12/11 15:32:13 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	has_died(t_philo *plato)
{
	pthread_mutex_lock(&plato->chef->write);
	printf("\x1b[31m%lu %d has died\x1b[0m\n", \
		my_time() - plato->chef->start, plato->philo_name);
}

void	has_taken_a_fork(t_philo *plato)
{
	pthread_mutex_lock(&plato->chef->write);
	printf("%lu %d has taken a fork\n", my_time()
		- plato->chef->start, plato->philo_name);
	pthread_mutex_unlock(&plato->chef->write);
}

void	is_eating(t_philo *plato)
{
	pthread_mutex_lock(plato->left_fork);
	has_taken_a_fork(plato);
	pthread_mutex_lock(plato->right_fork);
	has_taken_a_fork(plato);
	pthread_mutex_lock(&plato->lock);
	pthread_mutex_lock(&plato->chef->lock);
	plato->meals++;
	plato->is_eating = 1;
	plato->life_time = my_time() + plato->chef->die_time;
	pthread_mutex_unlock(&plato->lock);
	pthread_mutex_unlock(&plato->chef->lock);
	pthread_mutex_lock(&plato->chef->write);
	printf("\x1b[32m%lu %d is eating\x1b[0m\n", my_time()
		- plato->chef->start, plato->philo_name);
	pthread_mutex_unlock(&plato->chef->write);
	my_usleep(plato->chef->eat_time);
	pthread_mutex_lock(&plato->lock);
	plato->is_eating = 0;
	pthread_mutex_unlock(&plato->lock);
	pthread_mutex_unlock(plato->left_fork);
	pthread_mutex_unlock(plato->right_fork);
}

void	is_sleeping(t_philo *plato)
{
	pthread_mutex_lock(&plato->chef->write);
	printf("\x1b[34m%lu %d is sleeping\x1b[0m\n", my_time()
		- plato->chef->start, plato->philo_name);
	pthread_mutex_unlock(&plato->chef->write);
	my_usleep(plato->chef->sleep_time);
}

void	is_thinking(t_philo *plato)
{
	pthread_mutex_lock(&plato->chef->write);
	printf("\x1b[33m%lu %d is thinking\x1b[0m\n", my_time()
		- plato->chef->start, plato->philo_name);
	pthread_mutex_unlock(&plato->chef->write);
}
