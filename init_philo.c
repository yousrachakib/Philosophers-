/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:12:16 by yochakib          #+#    #+#             */
/*   Updated: 2023/05/27 12:17:52 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	fill_struct(t_list *info, int ac, char **av)
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
		gettimeofday(&info->philo->born_time, NULL);
		info->philo->last_meal = gettime();
		pthread_create(&info->philo->ph, NULL, &routine, info->philo);
		pthread_detach(info->philo->ph);
		info->philo = info->philo->next;
		if (info->philo->next == tmp)
			break ;
	}
	// check_id_died(info);
	while (1)
		;
}

void	print(char *str, t_philo *philo)
{
	long long	time ;

	pthread_mutex_lock(&philo->info->print_lock);
	time =  (gettime() - \
		((philo->born_time.tv_sec * 1000) + (philo->born_time.tv_usec / 1000)));
	printf("%lld %d %s", time, philo->philo_id, str);
	usleep(1000);
	pthread_mutex_unlock(&philo->info->print_lock);
}
