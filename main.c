/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:33:04 by vzashev           #+#    #+#             */
/*   Updated: 2023/12/12 15:33:48 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	put_forks(t_chef *chef)
{
	int	i;

	i = 0;
	while (i < chef->num_philos)
	{
		chef->philo[i].chef = chef;
		chef->philo[i].meals = 0;
		chef->philo[i].is_eating = 0;
		chef->philo[i].philo_name = i + 1;
		chef->philo[i].life_time = my_time() + chef->die_time;
		chef->philo[i].right_fork = &chef->forks[i];
		if (i == 0)
			chef->philo[i].left_fork = &chef->forks[chef->num_philos - 1];
		else
			chef->philo[i].left_fork = &chef->forks[i - 1];
		pthread_mutex_init(&chef->philo[i].lock, NULL);
		chef->philo[i].flag = 0;
		i++;
	}
}

void	mutex_init(t_chef *table)
{
	int	i;

	i = 0;
	while (i < table->num_philos)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&table->lock, NULL);
	pthread_mutex_init(&table->write, NULL);
	put_forks(table);
}

void	alloc_table(t_chef *table)
{
	table->philo = (t_philo *)malloc(sizeof(t_philo) * table->num_philos);
	if (!table->philo)
		exit (0);
	table->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* table->num_philos);
	if (!table->forks)
		exit (0);
	table->thread = (pthread_t *)malloc(sizeof(pthread_mutex_t) \
		* table->num_philos);
	if (!table->thread)
		exit (0);
	mutex_init(table);
}

void	init_table(t_chef *init_table, int argc, char **argv)
{
	init_table->num_philos = (my_atoi(argv[1]));
	init_table->die_time = ((u_int64_t)(my_atoi(argv[2])));
	init_table->eat_time = ((u_int64_t)my_atoi(argv[3]));
	init_table->sleep_time = ((u_int64_t)my_atoi(argv[4]));
	if (argv[5])
		init_table->must_meals = (my_atoi(argv[5]));
	else
		init_table->must_meals = -1;
	init_table->start = my_time();
	init_table->dead = 0;
	init_table->end = 0;
	my_check_input(init_table, argc);
	alloc_table(init_table);
}

int	main(int argc, char *argv[])
{
	t_chef		new_table;
	pthread_t	supervisor;
	int			i;

	i = -1;
	my_check(argc);
	init_table(&new_table, argc, argv);
	if (argc == 6)
	{
		if (pthread_create(&supervisor, NULL, &the_boss, &new_table))
			return (1);
		pthread_detach(supervisor);
	}
	while (++i < new_table.num_philos)
	{
		if (pthread_create(&new_table.thread[i], NULL, \
			&philo_routine, &new_table.philo[i]))
			return (1);
		pthread_detach(new_table.thread[i]);
		my_usleep(2.4);
	}
	while (!new_table.dead && !new_table.end)
		;
	my_exit(&new_table);
	return (0);
}
