/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:57:11 by yochakib          #+#    #+#             */
/*   Updated: 2023/05/18 20:44:09 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
size_t 	gettime(t_philo	*philo)
{
	size_t	tv;
	struct timeval time;
	gettimeofday(&time, NULL);
	tv = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (tv);
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
		printf("%zu %d has taken a fork\n", (gettime(philo) - ((philo->born_time.tv_sec * 1000) + (philo->born_time.tv_usec / 1000))), philo->philo_id);
		pthread_mutex_lock(&philo->next->fork);
		printf("%zu %d has taken a fork\n", (gettime(philo) - ((philo->born_time.tv_sec * 1000) + (philo->born_time.tv_usec / 1000))),philo->philo_id);
		printf("%zu %d is eating\n",(gettime(philo) - ((philo->born_time.tv_sec * 1000) + (philo->born_time.tv_usec / 1000))),philo->philo_id);
		usleep(philo->info->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		printf("%zu %d is sleeping\n", (gettime(philo) - ((philo->born_time.tv_sec * 1000) + (philo->born_time.tv_usec / 1000))),philo->philo_id);
		usleep(philo->info->time_to_sleep * 1000);
		printf("%zu %d is thinking\n", (gettime(philo) - ((philo->born_time.tv_sec * 1000) + (philo->born_time.tv_usec/ 1000))),philo->philo_id);
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