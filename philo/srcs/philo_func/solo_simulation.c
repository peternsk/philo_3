/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solo_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:41:54 by pnsaka            #+#    #+#             */
/*   Updated: 2024/01/22 12:02:10 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	*solo_routine(void *real_tab)
{
	t_philo	*philo;

	philo = (t_philo *)real_tab;
	print_statement(philo, THINKING);
	print_statement(philo, L_FORK);
	ft_usleep(philo->glb_s->time_to_die);
	print_statement(philo, DEAD);
	return (0);
}

void	one_philo(t_global *glb_s)
{
	int	i;

	i = 0;
	glb_s->strt_sim_time = actual_time();
	if (pthread_mutex_init(&glb_s->forks[i].fork, NULL) != 0)
		return ;
	glb_s->forks[i].id = i;
	if (pthread_create(&glb_s->asso_philo[i].platon, NULL, solo_routine,
			&glb_s->asso_philo[i]) != 0)
		ext_err("thread create error..");
	if (pthread_join(glb_s->asso_philo[i].platon, NULL) != 0)
		ext_err("omni_philo join error..");
}
