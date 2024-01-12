/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 08:45:53 by pnsaka            #+#    #+#             */
/*   Updated: 2024/01/12 12:02:09 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static void		*clean_malloc(size_t space_nd)
{
	void	*ret_val;
	ret_val = malloc(space_nd);
	if(ret_val == NULL)
		ext_err("malloc err..");
	return(ret_val);
}

static void		init_arr_mutx(t_philo *philo, t_fork *fork, int position)
{
	if(philo->id % 2 == 0)
	{
		philo->r_fork = &fork[position];
		philo->l_fork = &fork[(position + 1) % philo->glb_s->n_of_p];
	}
	philo->r_fork = &fork[(position + 1) % philo->glb_s->n_of_p];
	philo->l_fork = &fork[position];
	printf("platon right fork  %d\n", philo->r_fork->id);
	printf("platon left fork  %d\n", philo->l_fork->id);

}
static void		init_act_mtx(t_global *glb_s)
{
	if (pthread_mutex_init(&glb_s->action->eating, NULL) != 0)
			return ;
	if (pthread_mutex_init(&glb_s->action->sleeping, NULL) != 0)
			return ;
	if (pthread_mutex_init(&glb_s->action->writing, NULL) != 0)
			return ;
	if (pthread_mutex_init(&glb_s->action->mtx_plate, NULL) != 0)
			return ;
	if (pthread_mutex_init(&glb_s->action->check_philos, NULL) != 0)
			return ;
}

static void 	init_philo(t_global *glb_s)
{
    t_philo *platon;
    
	int i;

	i = -1;
	printf("=====> init_philo %d\n", glb_s->n_of_p);
	while(++i < glb_s->n_of_p)
	{
		platon = glb_s->asso_philo + i;
		platon->id = i + 1;
		printf("platon ID  %d\n", platon->id);
		platon->is_dead = false;
		platon->is_full = false;
		platon->plates 	= 0;
		platon->glb_s = glb_s;
		init_arr_mutx(platon, glb_s->forks, i);
	}
}

static void 	init_omni_philo(t_global *glb_s)
{
	glb_s->omni_philo->all_full = false;
	glb_s->omni_philo->one_dead = false;
}

void init_val(t_global *glb_s, char **val)
{
	int i;

	i = -1;
	glb_s->n_of_p        = ft_atol(val[1]);
	printf("====> init %d\n", glb_s->n_of_p);
	glb_s->time_to_die   = ft_atol(val[2]) * 1000;
	glb_s->time_to_eat   = ft_atol(val[3]) * 1000;
	glb_s->time_to_sleep = ft_atol(val[4]) * 1000;
    if(val[5])
	{
	    glb_s->must_eat  = ft_atol(val[5]);
		glb_s->plate_counter = true;
	}
	else
		glb_s->plate_counter = false;
	glb_s->omni_philo = clean_malloc(sizeof(t_omni_philo) * 1);
	glb_s->asso_philo = clean_malloc(sizeof(t_philo) * (glb_s->n_of_p));
	glb_s->forks = clean_malloc(sizeof(t_fork) * (glb_s->n_of_p));
	glb_s->action = clean_malloc(sizeof(t_mtx_act) * 1);
	while(++i <= glb_s->n_of_p)
	{
		if (pthread_mutex_init(&glb_s->forks[i].fork, NULL) != 0)
			return ;
		glb_s->forks[i].id = i;
	}
	init_philo(glb_s);
	init_omni_philo(glb_s);
	init_act_mtx(glb_s);
}

