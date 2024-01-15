/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 00:14:38 by peternsaka        #+#    #+#             */
/*   Updated: 2024/01/13 01:16:27 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"


static void	check_philo_dead(t_global *glb_s)
{
	int i;

	i = 0;
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

static void check_philo_all_full(t_global *glb_s)
{
    int i;
    int nb_of_full;

    i = 0;
    nb_of_full = 0;

    while (i < glb_s->n_of_p)
	{
        pthread_mutex_lock(&glb_s->action->mtx_plate);
        if (glb_s->asso_philo[i].is_full == true)
            nb_of_full++;
        pthread_mutex_unlock(&glb_s->action->mtx_plate);
        if (nb_of_full == glb_s->n_of_p)
		{
            pthread_mutex_lock(&glb_s->action->check_philos);
            glb_s->omni_philo->all_full = true;
            pthread_mutex_unlock(&glb_s->action->check_philos);
            printf("THEY ARE ALL DONE EATING MY GUY !!!\n");
            break;  // Exit the loop after setting all_full to true
        }
        i++;
    }
    return;
}

void	*monitoring(void *arg)
{
	t_global *glb_s;

	glb_s = (t_global *)arg;
	while(1)
	{
		pthread_mutex_lock(&glb_s->action->check_philos);
        if (glb_s->omni_philo->all_full)
		{
            pthread_mutex_unlock(&glb_s->action->check_philos);
            break;
        }
        pthread_mutex_unlock(&glb_s->action->check_philos);
		usleep(50000);
		check_philo_dead(glb_s);
		check_philo_all_full(glb_s);
	}
	return(0);
}