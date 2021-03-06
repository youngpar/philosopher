/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:06:55 by youngpar          #+#    #+#             */
/*   Updated: 2022/04/24 02:28:15 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	parse(int argc, char **argv, t_routine *routine)
{
	routine->philo_num = arg_toi(argv[1]);
	routine->time_to_die = arg_toi(argv[2]);
	routine->time_to_eat = arg_toi(argv[3]);
	routine->time_to_sleep = arg_toi(argv[4]);
	routine->exited.tv_sec = 0;
	routine->died = -1;
	routine->join = -1;
	if (argc == 6)
	{
		if (arg_toi(argv[5]) < 0)
			err_msg("Args Error\n");
		routine->at_least_eat = arg_toi(argv[5]);
	}
	else
		routine->at_least_eat = -1;
	if (routine->philo_num < 1 || routine->time_to_sleep < 0
		|| routine->time_to_eat < 0 || routine->time_to_die < 0)
		err_msg("Args Error\n");
}

int	main(int argc, char **argv)
{
	t_routine	routine;

	if (argc != 5 && argc != 6)
		err_msg("Arguments should be 4-5\n");
	parse(argc, argv, &routine);
	gettimeofday(&routine.start, NULL);
	initialize(&routine);
	//	join
	while (!routine.exited.tv_sec);
	if (routine.died != -1)
	{
		printf(TIME_STAMP, get_elapsed_ms(&routine.start, &routine.exited));
		printf(DIED, routine.died);
	}
	thread_exception_handler(&routine, routine.philo_num);
	forks_destroy(&routine, routine.philo_num);
	ticket_destroy(&routine, (routine.philo_num + 1) / 2);
	pthread_mutex_destroy(&routine.print_right);
	system("leaks philo | grep leaked");
	return (0);
}
