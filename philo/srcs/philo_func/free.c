/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:34:40 by pnsaka            #+#    #+#             */
/*   Updated: 2024/01/22 16:03:37 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static  void    dest_mtx(t_mtx_act *act_mtx, t_fork *fork)
{
    pthread_mutex_destroy(&act_mtx->eating);
    pthread_mutex_destroy(&act_mtx->sleeping);
    pthread_mutex_destroy(&act_mtx->writing);
    pthread_mutex_destroy(&act_mtx->mtx_plate);
    pthread_mutex_destroy(&act_mtx->check_philos);
    pthread_mutex_destroy(&fork->fork);
}
void    free_struct(t_philo *philo)
{
    int i;

    i = -1;
    dest_mtx(philo->glb_s->action, philo->glb_s->forks);
    free(philo->glb_s->action);
    free(philo->glb_s->omni_philo);
    free(philo->glb_s->forks);
    free(philo);
}
 