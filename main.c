/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:57:11 by yochakib          #+#    #+#             */
/*   Updated: 2023/05/20 15:09:50 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
long long 	gettime(t_philo	*philo)
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print(char *str, t_philo *philo)
{
	long long	value;
	pthread_mutex_lock(&philo->info->print_lock);
	value = (gettime(philo) - \
		((philo->born_time.tv_sec * 1000) + (philo->born_time.tv_usec / 1000)));
	printf("%lld %d %s ", value, (*philo).philo_id, str);
	pthread_mutex_unlock(&philo->info->print_lock);
}

void	*routine(void *ptr)
{
	t_philo *philo;
	
	philo = (t_philo *)ptr;
	if ((philo->philo_id % 2) == 0)
		usleep(200);
	while (1)
	{
		pthread_mutex_lock(&philo->fork);
		print("has taken a fork\n",philo);
		pthread_mutex_lock(&philo->next->fork);
		print("has taken a fork\n", philo);
		print("is eating\n", philo);
		pthread_mutex_lock(&philo->info->meals_counter_lock);
		philo->meals_counter++;
		philo->last_meal = gettime(philo);
		pthread_mutex_unlock(&philo->info->meals_counter_lock);
		usleep(philo->info->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		print("is sleeping\n", philo);
		usleep(philo->info->time_to_sleep * 1000);
		print("is thinking\n", philo);
	}
	return NULL;
}

int	main(int ac, char **av)
{
	t_info	info;
	
	if (ac != 5 && ac != 6)
		return (ft_putstr_fd("Error\nfew args", 2), 0);
	fill_struct(&info, ac, av);
	check_error(&info, ac, av);
	creat_philo(&info);
	

}