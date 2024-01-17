/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:30:22 by peternsaka        #+#    #+#             */
/*   Updated: 2024/01/17 14:14:23 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

long	actual_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (printf("Error time"), -1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long	last_time_eat(t_philo *philo)
{
	long time;
	
	time = actual_time();
	philo->lte = time;
}

bool	times_up(t_philo *philo)
{
	long chrono;
	long act_time;
	
	act_time = actual_time();
	chrono = act_time - philo->lte;
	if(chrono > philo->glb_s->time_to_die)
		return(true);
	else
		return(false);
}