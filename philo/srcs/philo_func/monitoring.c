/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 00:14:38 by peternsaka        #+#    #+#             */
/*   Updated: 2024/01/12 13:23:23 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"


static void	check_philo_dead(t_global *glb_s)
{
	int i;

	i = 0;
	printf("=====> dead %d\n", glb_s->n_of_p);
	while(i < glb_s->n_of_p)
	{
		pthread_mutex_lock(&glb_s->action->check_philos);
		if(glb_s->asso_philo[i].is_dead == true)
		{
			usleep(2000);
			glb_s->omni_philo->one_dead = true; 
			break;
		}
		pthread_mutex_unlock(&glb_s->action->check_philos);
		i++;
	}
	return;
}
static void	check_philo_all_full(t_global *glb_s)
{
	int i;
	int nb_of_full;

	i = 0;
	nb_of_full = 0;
	while(i < glb_s->n_of_p )
	{
		usleep(2000);
		pthread_mutex_lock(&glb_s->action->mtx_plate);
		if(glb_s->asso_philo[i].is_full == true)
		{
			nb_of_full++;
			pthread_mutex_unlock(&glb_s->action->mtx_plate);	
		}
		printf("nb of full %d nb of philo %d\n", nb_of_full, glb_s->n_of_p);
		if(nb_of_full == glb_s->n_of_p)
		{
			glb_s->omni_philo->all_full = true;
			printf(" THEY ARE ALL DONE EATING MY GUY !!!\n");	
		}
		i++;
		pthread_mutex_unlock(&glb_s->action->mtx_plate);
	}
	return;
}

void	*monitoring(void *arg)
{
	t_global *glb_s;

	glb_s = (t_global *)arg;
	printf("=====> monitoring %d\n", glb_s->n_of_p);
	while(1)
	{
		printf("====> check_philo_dead <====\n");
		check_philo_dead(glb_s);
		printf("====> check_philo_all_full <====\n");
		check_philo_all_full(glb_s);
	}
	return(0);
}