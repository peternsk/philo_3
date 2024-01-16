/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:30:22 by peternsaka        #+#    #+#             */
/*   Updated: 2024/01/16 09:54:04 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

/*
	time since the begining on computer.
*/

long	actual_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (printf("Error time"), -1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

// int main(void)
// {
// 	struct timeval now_time;
// 	gettimeofday(&now_time, NULL);
// 	printf("second : %ld\nmicrosecond : %d\n", now_time.tv_sec, now_time.tv_usec);
// 	printf("second : %ld\nmicrosecond : %d\n", now_time.tv_sec * 1000, now_time.tv_usec * 1000);
// } 