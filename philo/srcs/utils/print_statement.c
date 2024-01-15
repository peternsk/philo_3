/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_statement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 23:59:10 by peternsaka        #+#    #+#             */
/*   Updated: 2024/01/15 14:51:48 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	print_statement(t_philo *philo, char *stmt)
{
	long time;

	time = /* function gettimeofday - time exc*/
	pthread_mutex_lock(&philo->glb_s->action->writing);
	printf("philo  %ld %d %s\n", /* time*/ philo->id, stmt);
	pthread_mutex_unlock(&philo->glb_s->action->writing);
}