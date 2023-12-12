/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:32:55 by vzashev           #+#    #+#             */
/*   Updated: 2023/12/11 15:40:23 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	my_free(t_chef	*chef)
{
	if (chef->thread)
		free(chef->thread);
	if (chef->forks)
		free(chef->forks);
	if (chef->philo)
		free(chef->philo);
}

void	my_exit(t_chef *chef)
{
	int	i;

	i = -1;
	while (++i < chef->num_philos)
	{
		pthread_mutex_destroy(&chef->forks[i]);
		pthread_mutex_destroy(&chef->philo[i].lock);
	}
	pthread_mutex_destroy(&chef->write);
	pthread_mutex_destroy(&chef->lock);
	my_free(chef);
}

int	my_error(char *mess, t_chef *chef)
{
	printf("%s\n", mess);
	if (chef)
		my_exit(chef);
	return (1);
}

u_int64_t	my_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (my_error("gettimeofday() FAILURE\n", NULL));
	return ((time.tv_sec * (u_int64_t)1000) + (time.tv_usec / (u_int64_t)1000));
}

int	my_usleep(u_int64_t time)
{
	u_int64_t	start;

	start = my_time();
	while ((my_time() - start) < time)
		usleep(time / 10);
	return (0);
}
