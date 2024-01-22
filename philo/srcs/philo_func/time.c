/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:30:22 by peternsaka        #+#    #+#             */
/*   Updated: 2024/01/19 08:50:36 by pnsaka           ###   ########.fr       */
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

void	last_time_eat(t_philo *philo)
{
	long	time;

	time = actual_time() - philo->glb_s->strt_sim_time;
	philo->lte = time;
}

void	times_up(t_philo *philo)
{
	long	chrono;
	long	act_time;

	act_time = actual_time();
	pthread_mutex_lock(&philo->glb_s->action->check_philos);
	pthread_mutex_lock(&philo->glb_s->action->eating);
	chrono = (act_time - philo->glb_s->strt_sim_time) - philo->lte;
	pthread_mutex_unlock(&philo->glb_s->action->eating);
	if (chrono >= philo->glb_s->time_to_die)
	{
		philo->is_dead = true;
		pthread_mutex_unlock(&philo->glb_s->action->check_philos);
		print_statement(philo, DEAD);
		return ;
	}
	else
		pthread_mutex_unlock(&philo->glb_s->action->check_philos);
	return ;
}

void	ft_usleep(long time)
{
	long	start;

	start = actual_time();
	while (actual_time() - start < time)
		usleep(150);
}
