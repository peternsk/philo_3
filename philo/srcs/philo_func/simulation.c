/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 23:59:10 by peternsaka        #+#    #+#             */
/*   Updated: 2024/01/22 11:59:56 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static void	count_plate(t_philo *philo)
{
	pthread_mutex_lock(&philo->glb_s->action->mtx_plate);
	if (philo->glb_s->must_eat > 0 && philo->glb_s->plate_counter == true)
	{
		pthread_mutex_unlock(&philo->glb_s->action->mtx_plate);
		if (philo->plates != philo->glb_s->must_eat)
			philo->plates++;
		else
		{
			pthread_mutex_lock(&philo->glb_s->action->mtx_plate);
			philo->is_full = true;
			print_statement(philo, FULL);
			pthread_mutex_unlock(&philo->glb_s->action->mtx_plate);
		}
	}
	else
		pthread_mutex_unlock(&philo->glb_s->action->mtx_plate);
}

void	eat_func(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork->fork);
	print_statement(philo, L_FORK);
	pthread_mutex_lock(&philo->r_fork->fork);
	print_statement(philo, R_FORK);
	print_statement(philo, EAT);
	ft_usleep(philo->glb_s->time_to_eat);
	pthread_mutex_lock(&philo->glb_s->action->eating);
	philo->lte = actual_time() - philo->glb_s->strt_sim_time;
	count_plate(philo);
	pthread_mutex_unlock(&philo->glb_s->action->eating);
	pthread_mutex_unlock(&philo->l_fork->fork);
	print_statement(philo, RL_FORK);
	pthread_mutex_unlock(&philo->r_fork->fork);
	print_statement(philo, RR_FORK);
}

void	pause_func(t_philo *philo)
{
	print_statement(philo, SLEEP);
	ft_usleep(philo->glb_s->time_to_sleep);
}

void	*simulation(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
	{
		print_statement(philo, THINKING);
		ft_usleep(philo->glb_s->time_to_eat / 10);
	}
	while (1)
	{
		pthread_mutex_lock(&philo->glb_s->action->check_philos);
		if (philo->glb_s->omni_philo->all_full == false
			&& philo->glb_s->omni_philo->one_dead == false)
		{
			pthread_mutex_unlock(&philo->glb_s->action->check_philos);
			eat_func(philo);
			pause_func(philo);
		}
		else
		{
			pthread_mutex_unlock(&philo->glb_s->action->check_philos);
			break ;
		}
	}
	return (NULL);
}
