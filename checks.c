/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:36:25 by vzashev           #+#    #+#             */
/*   Updated: 2023/12/12 15:33:04 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	my_check_input(t_chef *table, int argc)
{
	if (table->num_philos == 0)
	{
		printf("\x1b[31mError: it's needed at least one philosopher!\x1b[0m\n");
		exit(0);
	}
	else if (table->num_philos < 0)
	{
		printf("\x1b[31mError: Wrong philosopher parameter inserted!\x1b[0m\n");
		exit(0);
	}
	if (table->die_time <= 0 || table->eat_time <= 0
		|| table->sleep_time <= 0)
	{
		printf("\x1b[31mError: Wrong time parameter inserted!\x1b[0m\n");
		exit(0);
	}
	if (argc == 6 && table->must_meals <= 0)
	{
		printf("\x1b[31mError: Wrong must meals number inserted!\x1b[0m\n");
		exit(0);
	}
}

void	my_check(int argc)
{
	if ((argc != 5) && (argc != 6))
	{
		printf("\x1b[31mError: the arguments given aren't \
			neither 4 nor 5!\x1b[0m\n");
		exit (0);
	}
}
