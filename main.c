/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:21:46 by yochakib          #+#    #+#             */
/*   Updated: 2023/05/28 18:55:34 by yochakib         ###   ########.fr       */
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
	while (philo->info->death_index == 0)
	{
		pthread_mutex_lock(&philo->fork);
		pthread_mutex_lock(&philo->info->print_lock);
		print("has taken a fork\n", philo);
		pthread_mutex_unlock(&philo->info->print_lock);
		pthread_mutex_lock(&philo->next->fork);
		pthread_mutex_lock(&philo->info->print_lock);		
		print(" has taken a fork\n", philo);
		pthread_mutex_unlock(&philo->info->print_lock);
		// pthread_mutex_lock(&philo->info->meals_counter_lock);
		philo->meals_counter += 1;
		// pthread_mutex_unlock(&philo->info->meals_counter_lock)
		pthread_mutex_lock(&philo->info->print_lock);
		print("is eating\n", philo);
		pthread_mutex_unlock(&philo->info->print_lock);
		ft_usleep(philo->info->time_to_eat);
		philo->last_meal = gettime();
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		pthread_mutex_lock(&philo->info->print_lock);
		print("is sleeping\n", philo);
		pthread_mutex_unlock(&philo->info->print_lock);
		ft_usleep(philo->info->time_to_sleep);		
		pthread_mutex_lock(&philo->info->print_lock);
		print("is thinking\n", philo);
		pthread_mutex_unlock(&philo->info->print_lock);
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
	check_error(&info, ac, av);
	creat_philo(&info);
	return (0);
}
