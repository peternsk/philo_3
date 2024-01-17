/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_statement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 23:59:10 by peternsaka        #+#    #+#             */
/*   Updated: 2024/01/15 10:50:37 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	print_statement(t_philo *philo, char *stmt)
{
	pthread_mutex_lock(&philo->glb_s->action->mtx_plate);
	if(philo->is_full == false)
	{
		pthread_mutex_unlock(&philo->glb_s->action->mtx_plate);
		pthread_mutex_lock(&philo->glb_s->action->writing);
		printf("philo %d %s\n", philo->id, stmt);
		pthread_mutex_unlock(&philo->glb_s->action->writing);
	}
	pthread_mutex_unlock(&philo->glb_s->action->mtx_plate);
	
}