/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:10:35 by pnsaka            #+#    #+#             */
/*   Updated: 2024/01/22 11:57:49 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	*start_thread(t_global *glb_s)
{
	int	i;

	i = -1;
	glb_s->strt_sim_time = actual_time();
	while (++i < glb_s->n_of_p)
		if (pthread_create(&glb_s->asso_philo[i].platon, NULL, simulation,
				&glb_s->asso_philo[i]) != 0)
			ext_err("thread create error..");
	if (pthread_create(&glb_s->omni_philo->omni_philo, NULL, monitoring,
			glb_s) != 0)
		ext_err("omni_philo create error..");
	i = -1;
	while (++i < glb_s->n_of_p)
		if (pthread_join(glb_s->asso_philo[i].platon, NULL) != 0)
			ext_err("thread join error..");
	if (pthread_join(glb_s->omni_philo->omni_philo, NULL) != 0)
		ext_err("omni_philo join error..");
	return (0);
}
