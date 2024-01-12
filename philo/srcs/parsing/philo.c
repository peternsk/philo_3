/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:58:01 by pnsaka            #+#    #+#             */
/*   Updated: 2024/01/08 10:46:51 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	main(int argc, char **argv)
{
	t_global glb_s;
	
	(void)argv;
	if (argc == 5 || argc == 6)
	{
		if(parser(/*&glb_s,*/ argv) == false)
			ext_err("parssing error..");
		init_val(&glb_s, argv);
		start_thread(&glb_s);
	}
	else
		ext_err("missing arg\n");
	return (0);
}
