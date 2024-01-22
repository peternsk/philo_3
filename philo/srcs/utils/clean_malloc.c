/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 08:52:27 by pnsaka            #+#    #+#             */
/*   Updated: 2024/01/19 08:52:57 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	*clean_malloc(size_t space_nd)
{
	void	*ret_val;

	ret_val = malloc(space_nd);
	if (ret_val == NULL)
		ext_err("malloc err..");
	return (ret_val);
}