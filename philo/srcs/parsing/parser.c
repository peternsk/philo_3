/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:56:44 by pnsaka            #+#    #+#             */
/*   Updated: 2024/01/22 09:34:13 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

bool	parser(char **val)
{
	int	i;

	i = 1;
	while (val[i] != NULL)
	{
		if (check_dig_arg(val[i]) == false)
			return (false);
		if (check_sign_arg(val[i]) == false)
			return (false);
		i++;
	}
	return (true);
}
