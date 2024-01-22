/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 08:57:11 by pnsaka            #+#    #+#             */
/*   Updated: 2024/01/19 08:57:39 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	init_all(t_global *glb_s, char **val)
{
	init_val(glb_s, val);
	init_philo(glb_s);
	init_omni_philo(glb_s);
	init_act_mtx(glb_s);
}
