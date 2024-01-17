/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 23:59:10 by peternsaka        #+#    #+#             */
/*   Updated: 2024/01/15 10:52:17 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static	void	count_plate(t_philo *philo) // a travailler
{
	pthread_mutex_lock(&philo->glb_s->action->mtx_plate);
	if(philo->glb_s->must_eat > 0 && philo->glb_s->plate_counter == true)
	{
		pthread_mutex_unlock(&philo->glb_s->action->mtx_plate);
		if(philo->plates != philo->glb_s->must_eat)
		{
			philo->plates++;
			printf("philo ID %d num of plate %d\n",philo->id, philo->plates);
		}
		else
		{
			pthread_mutex_lock(&philo->glb_s->action->mtx_plate);
			philo->is_full = true;
			pthread_mutex_unlock(&philo->glb_s->action->mtx_plate);
			printf(" philo %d %s\n", philo->id, FULL);
		}
	}
	pthread_mutex_unlock(&philo->glb_s->action->mtx_plate);
}

void	eat_func(t_philo *philo) // a travailler
{
	pthread_mutex_lock(&philo->l_fork->fork);
	print_statement(philo, L_FORK);
	pthread_mutex_lock(&philo->r_fork->fork);
	print_statement(philo, R_FORK);
	
	//eating 
	pthread_mutex_lock(&philo->glb_s->action->eating);
	usleep(philo->glb_s->time_to_eat);
	print_statement(philo, EAT);
	count_plate(philo);
	pthread_mutex_unlock(&philo->glb_s->action->eating);
	
	//unlocc
	pthread_mutex_unlock(&philo->l_fork->fork);
	print_statement(philo, RL_FORK);
	pthread_mutex_unlock(&philo->r_fork->fork);
	print_statement(philo, RR_FORK);
}


void	pause_func(t_philo *philo) // a travailler
{
	printf("philo %d %s\n", philo->id, THINKING);
	usleep(philo->glb_s->time_to_eat * 2);
}

void *simulation(void *arg)
{
    t_philo *philo;
    philo = (t_philo *)arg;

    while (1)
	{
        pthread_mutex_lock(&philo->glb_s->action->check_philos);
        if (philo->glb_s->omni_philo->all_full)
		{
            pthread_mutex_unlock(&philo->glb_s->action->check_philos);
            break;
        }
        pthread_mutex_unlock(&philo->glb_s->action->check_philos);
        eat_func(philo);
        pause_func(philo);
    }
    printf(" ===>> voila !!!!!!!!!!!!!\n");
    return NULL;
}

