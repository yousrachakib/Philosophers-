/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:18:18 by yochakib          #+#    #+#             */
/*   Updated: 2023/05/20 15:09:07 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	fill_struct(t_info	*info, int ac, char **av)
{	
	pthread_mutex_init(&info->death_lock, NULL);
	pthread_mutex_init(&info->print_lock, NULL);
	pthread_mutex_init(&info->meals_counter_lock, NULL);
	info->number_of_philosophers = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
}

void	creat_philo(t_info *info)
{
	
	t_philo *tmp;

	info->philo = NULL;
	int i = 1;
	while (i <= info->number_of_philosophers)
		addback_node(&info->philo, create_node(i++, info));
	tmp = info->philo;
	while (info->philo)
	{	
		info->philo->last_meal = gettime(info->philo);
		gettimeofday(&info->philo->born_time, NULL);
		pthread_create(&info->philo->ph, NULL, &routine, info->philo);
		pthread_detach(info->philo->ph);
		info->philo = info->philo->next;
		if (info->philo == tmp)
			break;
	}
	while (1)
	{
		pthread_mutex_lock(&info->death_lock);
		if(gettime(info->philo) - info->philo->last_meal >= info->time_to_die)
		{
			print("is dead\n", info->philo);
			break;
		}
		pthread_mutex_unlock(&info->death_lock);
		info->philo = info->philo->next;
	}
	
}