/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_statement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 23:59:10 by peternsaka        #+#    #+#             */
/*   Updated: 2024/01/16 09:52:06 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	print_statement(t_philo *philo, char *stmt)
{
	pthread_mutex_lock(&philo->glb_s->action->writing);
	printf("philo %d %s\n", philo->id, stmt);
	pthread_mutex_unlock(&philo->glb_s->action->writing);
}