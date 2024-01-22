/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 00:14:38 by peternsaka        #+#    #+#             */
/*   Updated: 2024/01/22 12:14:36 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	check_philo_dead(t_global *glb_s)
{
	int	i;

	i = 0;
	while (i < glb_s->n_of_p)
	{
		times_up(&glb_s->asso_philo[i]);
		pthread_mutex_lock(&glb_s->action->check_philos);
		if (glb_s->asso_philo[i].is_dead == true)
		{
			usleep(2000);
			pthread_mutex_unlock(&glb_s->action->check_philos);
			glb_s->omni_philo->one_dead = true;
			print_statement(&glb_s->asso_philo[i], DEAD);
			break ;
		}
		else
			pthread_mutex_unlock(&glb_s->action->check_philos);
		i++;
	}
	return ;
}

void	check_philo_all_full(t_global *glb_s)
{
	int	i;
	int	nb_of_full;

	i = -1;
	nb_of_full = 0;
	while (++i < glb_s->n_of_p)
	{
		pthread_mutex_lock(&glb_s->action->mtx_plate);
		if (glb_s->asso_philo[i].is_full == true)
		{
			pthread_mutex_unlock(&glb_s->action->mtx_plate);
			nb_of_full++;
		}
		else
			pthread_mutex_unlock(&glb_s->action->mtx_plate);
		if (nb_of_full == glb_s->n_of_p)
		{
			pthread_mutex_lock(&glb_s->action->check_philos);
			glb_s->omni_philo->all_full = true;
			pthread_mutex_unlock(&glb_s->action->check_philos);
			printf("THEY ARE ALL DONE EATING !!! 🍽️\n");
			break ;
		}
	}
	return ;
}

void	*monitoring(void *arg)
{
	t_global	*glb_s;

	glb_s = (t_global *)arg;
	while (1)
	{
		pthread_mutex_lock(&glb_s->action->check_philos);
		if (glb_s->omni_philo->all_full == false
			&& glb_s->omni_philo->one_dead == false)
		{
			pthread_mutex_unlock(&glb_s->action->check_philos);
			usleep(5000);
			check_philo_dead(glb_s);
			check_philo_all_full(glb_s);
		}
		else
		{
			pthread_mutex_unlock(&glb_s->action->check_philos);
			break ;
		}
	}
	return (0);
}
