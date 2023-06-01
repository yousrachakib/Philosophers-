/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:21:46 by yochakib          #+#    #+#             */
/*   Updated: 2023/06/01 21:13:06 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(long long n)
{
	long long	tv;

	tv = gettime();
	while ((gettime()) < (tv + n))
		usleep(400);
}

long long	gettime(void)
{
	struct timeval	time;
	long long tv;

	gettimeofday(&time, NULL);
	tv = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (tv);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	if ((philo->philo_id) % 2 == 0)
		usleep(100 * 1000);
	while (1)
	{
		lock_forks(philo);
		start_eating(philo);
		go_bed(philo);
		now_overthink(philo);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_list	info;

	if (ac != 5 && ac != 6)
	{
		ft_putstr_fd("Error\nfew ARGUMENTS", 2);
		return (1);
	}
	fill_struct(&info, ac, av);
	if (check_error(&info, ac, av) == 0)
		return (1);
	creat_philo(&info);
	freelist(&info.philo);
	pthread_mutex_destroy(&info.death_lock);
	pthread_mutex_destroy(&info.meals_counter_lock);
	pthread_mutex_destroy(&info.print_lock);
	return (0);
}
