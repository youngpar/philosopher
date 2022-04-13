/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:40:48 by youngpar          #+#    #+#             */
/*   Updated: 2022/04/13 20:40:49 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

/*
 * Philosopher
 */

# define TRUE	1
# define FALSE	0

typedef int 				t_bool;
typedef struct s_philo		t_philo;
typedef struct s_routine	t_routine;
typedef long long			t_ll;
typedef unsigned long long	t_ull;

struct s_routine
{
	int 	philo_num;
	int 	time_to_die;
	int 	time_to_eat;
	int 	time_to_sleep;
	int 	at_least_eat;
	int 	died;
	t_ll	ts_start;
};

struct s_philo
{
	int			no;
	int			meal_cnt;
	t_ll		last_meal;
	t_routine	*routine;
	pthread_t 	thread_id;
};



/*
 * Exceptions
 */
void	err_msg(char *msg);


/*
 * Util
 */
t_bool	is_space(char c);
int 	arg_toi(char *s);
#endif //PHILO_H