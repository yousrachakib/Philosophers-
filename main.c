/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:57:11 by yochakib          #+#    #+#             */
/*   Updated: 2023/05/15 20:10:24 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *ptr)
{
	t_philo *philo;
	
	philo = (t_philo *)ptr;
	if ((philo->philo_id % 2) == 0)
		usleep(200);
	while (1)
	{
		pthread_mutex_lock(&philo->fork);
		printf("timestamp_in_ms %d has taken a fork\n", philo->philo_id);
		pthread_mutex_lock(&philo->next->fork);
		printf("timestamp_in_ms %d has taken a fork\n", philo->philo_id);
		printf("timestamp_in_ms %d is eating\n", philo->philo_id);
		usleep(philo->info->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		printf("timestamp_in_ms %d is sleeping\n", philo->philo_id);
		usleep(philo->info->time_to_sleep * 1000);
		printf("timestamp_in_ms %d is thinking\n", philo->philo_id);
	}
	return NULL;
	
}

int	main(int ac, char **av)
{
	t_info	info;
	t_philo *tmp;
	
	if (ac != 5 && ac != 6)
		return (ft_putstr_fd("Error\nfew args", 2), 0);
	fill_struct(&info, ac, av);
	check_error(&info, ac, av);
	creat_philo(&info);

}