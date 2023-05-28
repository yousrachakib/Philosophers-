/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:12:16 by yochakib          #+#    #+#             */
/*   Updated: 2023/05/28 18:56:33 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*fill_struct(t_list *info, int ac, char **av)
{
	if (ac == 6)
		info->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	info->number_of_philosophers = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->death_index = 0;
	pthread_mutex_init(&info->meals_counter_lock, NULL); //needs protection
	pthread_mutex_init(&info->print_lock, NULL);
	pthread_mutex_init(&info->death_lock, NULL);
	return (0);
}

void	creat_philo(t_list	*info)
{
	int		i;
	t_philo	*tmp;

	info->philo = NULL;
	i = 1;
	while (i <= info->number_of_philosophers)
	{
		addback_node(&info->philo, create_node(i, info));
		i++;
	}
	tmp = info->philo;
	while (info->philo)
	{
		info->born_time = gettime();
		info->philo->last_meal = gettime();
		pthread_create(&info->philo->ph, NULL, &routine, info->philo);
		pthread_detach(info->philo->ph);
		info->philo = info->philo->next;
		if (info->philo == tmp)
			break ;
	}
	check_if_died(info);
}

void	print(char *str, t_philo *philo)
{
	long long	time ;

	time = (gettime() - philo->info->born_time);
	printf("%lld %d %s", time, philo->philo_id, str);
}
