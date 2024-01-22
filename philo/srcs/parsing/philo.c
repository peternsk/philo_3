/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:58:01 by pnsaka            #+#    #+#             */
/*   Updated: 2024/01/22 16:02:51 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	main(int argc, char **argv)
{
	t_global	glb_s;

	(void)argv;
	if (argc == 5 || argc == 6)
	{
		if (parser(argv) == false)
			ext_err("parsing error..");
		init_all(&glb_s, argv);
		if (glb_s.time_to_die < 06 || glb_s.time_to_eat < 60
			|| glb_s.time_to_sleep < 60)
			ext_err("not enough time...");
		if (glb_s.n_of_p == 1)
			one_philo(&glb_s);
		else
			start_thread(&glb_s);
		free_struct(glb_s.asso_philo);
	}
	else
		ext_err("missing arg\n");
	return (0);
}
