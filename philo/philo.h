/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:54:10 by pnsaka            #+#    #+#             */
/*   Updated: 2024/01/22 15:10:12 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define EAT " is eating 🍝"
# define SLEEP " is sleeping 😴"
# define THINKING " is thinking 🧠"
# define L_FORK " has the left fork "
# define R_FORK " has the right fork"
# define RL_FORK " has release the left fork"
# define RR_FORK " has release the right fork"
# define FULL " is full 🍉"
# define DEAD " is dead 💀"

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				id;
}					t_fork;

typedef struct s_omni_philo
{
	pthread_t		omni_philo;
	bool			all_full;
	bool			one_dead;
}					t_omni_philo;

typedef struct s_mtx_act
{
	pthread_mutex_t	eating;
	pthread_mutex_t	sleeping;
	pthread_mutex_t	writing;
	pthread_mutex_t	mtx_plate;
	pthread_mutex_t	check_philos;
}					t_mtx_act;

typedef struct s_philo
{
	int				id;
	bool			is_dead;
	bool			is_full;
	int				plates;
	long			lte;
	pthread_t		platon;
	t_fork			*r_fork;
	t_fork			*l_fork;
	struct s_global	*glb_s;
}					t_philo;

typedef struct s_global
{
	int				n_of_p;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				must_eat;
	bool			plate_counter;
	long			strt_sim_time;
	
	pthread_mutex_t	eat;
	pthread_mutex_t	sleep;
	
	t_mtx_act		*action;
	t_fork			*forks;
	t_philo			*asso_philo;
	t_omni_philo	*omni_philo;

}					t_global;

/* parsing */
bool				check_dig_arg(char *str);
bool				check_sign_arg(char *str);
bool				parser(char **av);

/*-- philo_func --*/
void				init_val(t_global *glb_s, char **val);
void				*start_thread(t_global *glb_s);
void				eat_func(t_philo *philo);
void				*simulation(void *arg);
void				*monitoring(void *arg);

/*-- time_func --*/
long				actual_time(void);
void				ft_usleep(long time);
void				last_time_eat(t_philo *philo);
void				times_up(t_philo *philo);

/*-- solo philo --*/
void				one_philo(t_global *glb_s);

/*-- free --*/
void   			 	free_struct(t_philo *philo);

/*-- utils --*/
long				ft_atol(char *str);
void				print_statement(t_philo *philo, char *stmt);
void				ext_err(char *err_str);
void				*clean_malloc(size_t space_nd);

/*-- init --*/
void				init_all(t_global *glb_s, char **val);
void				init_arr_mutx(t_philo *philo, t_fork *fork, int position);
void				init_act_mtx(t_global *glb_s);
void				init_philo(t_global *glb_s);
void				init_omni_philo(t_global *glb_s);
void				init_val(t_global *glb_s, char **val);

#endif