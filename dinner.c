/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:36:21 by vzashev           #+#    #+#             */
/*   Updated: 2023/12/12 14:46:46 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*the_boss(void *new_table)
{
	int		i;
	t_chef	*table;

	i = 0;
	table = (t_chef *)new_table;
	while (!table->end && !table->dead)
	{
		i = -1;
		while (++i < table->num_philos)
		{
			if (table->philo[i].meals < table->must_meals)
				break ;
		}
		if (i == table->num_philos)
		{
			pthread_mutex_lock(&table->lock);
			table->end = 1;
			my_usleep(42);
			pthread_mutex_unlock(&table->lock);
		}
	}
	return (NULL);
}

void	*the_monitor(void *socrates)
{
	t_philo	*plato;

	plato = (t_philo *)socrates;
	while (!(plato->chef->dead) && !(plato->chef->end))
	{
		pthread_mutex_lock(&plato->lock);
		if ((my_time() >= plato->life_time) && (!plato->is_eating))
		{
			pthread_mutex_unlock(&plato->lock);
			pthread_mutex_lock(&plato->chef->lock);
			has_died(plato);
			plato->chef->dead = 1;
			my_usleep(10420);
			pthread_mutex_unlock(&plato->chef->write);
			pthread_mutex_unlock(&plato->chef->lock);
			break ;
		}
		pthread_mutex_unlock(&plato->lock);
	}
	return (NULL);
}

void	*philo_routine(void	*yeat)
{
	t_philo	*philo;

	philo = (t_philo *)yeat;
	if (pthread_create(&philo->thread, NULL, &the_monitor, (void *)philo))
		return (NULL);
	while (!(philo->chef->dead) && !(philo->chef->end))
	{
		is_eating(philo);
		is_sleeping(philo);
		is_thinking(philo);
	}
	return (NULL);
}
