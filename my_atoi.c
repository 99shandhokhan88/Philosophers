/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:32:31 by vzashev           #+#    #+#             */
/*   Updated: 2023/12/12 15:10:38 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	my_check_error(long int e)
{
	(void)e;
	printf("\x1b[31mError: over max int or below min int!\x1b[0m\n");
	exit (0);
}

static int	my_digit(char d)
{
	return ((d >= '0' && d <= '9'));
}

static int	my_sign(char si)
{
	return (si == '-' || si == '+');
}

static int	my_space(char s)
{
	return ((s >= '\t' && s <= '\r') || (s == 32));
}

int	my_atoi(const char *str)
{
	char		*arg;
	int			sign;
	long int	res;

	arg = (char *) str;
	sign = 1;
	res = 0;
	while (my_space(*arg))
		arg++;
	if (my_sign(*arg))
	{
		if (*arg == '-')
			sign = -1;
		arg++;
	}
	while (my_digit((int) *arg))
	{
		res *= 10;
		res += *(arg++) - 48;
	}
	if ((res * sign) > INT_MAX || (res * sign) < INT_MIN)
		my_check_error(res);
	return (res * sign);
}
