/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:54:10 by pnsaka            #+#    #+#             */
/*   Updated: 2024/01/16 09:47:09 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

# define EAT		" is eating 🍝"
# define SLEEP		" is sleeping 😴"
# define THINKING	" is thinking 🧠"
# define L_FORK 	" has the left fork "
# define R_FORK 	" has the right fork"
# define RL_FORK 	" has release the left fork"
# define RR_FORK 	" has release the right fork"
# define FULL		" is full 🍉"
# define DEAD		" is dead 💀"

typedef struct s_fork
{
	pthread_mutex_t fork;
	int				id;
}			t_fork;

typedef struct s_omni_philo
{
	pthread_t		omni_philo;			// the philo
	bool			all_full;
	bool			one_dead;
} 			   t_omni_philo;


typedef struct s_mtx_act
{
	pthread_mutex_t eating;
	pthread_mutex_t sleeping;
	pthread_mutex_t writing;
	pthread_mutex_t mtx_plate;
	pthread_mutex_t check_philos;
} 			t_mtx_act;


typedef struct s_philo
{
	int				id;				// rank of the philo in the array
	bool			is_dead; 		// flag that will be raised if philo is dead
	bool			is_full;		// flag that will be raised if philo is full
	int				plates;			// number of plates philo has eaten
	long			lte;			// last time eat
	pthread_t		platon;			// the philo
	t_fork			*r_fork;		// the fork the philo
	t_fork			*l_fork;		// a pointer to the fork of the philo beside
	struct s_global	*glb_s;			// a pointer to the global structure for philo to have asses
}					t_philo;

typedef struct s_global
{
	int				n_of_p;			// total number of philo
	long			time_to_die;	// limit time to die
	long			time_to_eat;	// limit time to eat
	long			time_to_sleep;	// time that philo si sleeping
	int				must_eat;
	bool			plate_counter;	// number of plate the philo must eat
	long			strt_sim_time;	// time at the beginning of the simulation
	pthread_mutex_t	eat;			// the mutex that will be lock or unlock by philo when eating
	pthread_mutex_t	sleep;			// the mutex that will be lock or unlock by philo when sleeping	// the thread that will monitor the philo.
	t_mtx_act		*action;		// the mutexs that will be lock/unlock when the philo is doing an action
	t_fork			*forks;			// an array of all the forks
	t_philo			*asso_philo;
	t_omni_philo	*omni_philo;	// an array of all the philos

}					t_global;

/* parsing */
bool				check_dig_arg(char *str);
bool				check_sign_arg(char *str);
bool				parser(/*t_global *glb_s,*/ char **av);

/*-- philo_func --*/
void 				init_val(t_global *glb_s, char **val);
void    			*start_thread(t_global *glb_s);
void				eat_func(t_philo *philo);
void				*simulation(void *arg);
void				*monitoring(void *arg);

/*-- time_func --*/
long				actual_time(void);

/*-- utils --*/
long				ft_atol(char *str);
void				print_statement(t_philo *philo, char *stmt);
void				ext_err(char *err_str);

#endif