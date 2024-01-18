/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_statement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 23:59:10 by peternsaka        #+#    #+#             */
/*   Updated: 2024/01/18 16:50:18 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	print_statement(t_philo *philo, char *stmt)
{
	long time;

	time = actual_time() - philo->glb_s->strt_sim_time;
	
    pthread_mutex_lock(&philo->glb_s->action->check_philos);
	if(philo->glb_s->omni_philo->all_full == false && philo->glb_s->omni_philo->one_dead == false)
		printf("%ld %d %s\n", time, philo->id, stmt);
    pthread_mutex_unlock(&philo->glb_s->action->check_philos);
}