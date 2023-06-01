/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:28:56 by yochakib          #+#    #+#             */
/*   Updated: 2023/06/01 19:09:24 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_if_died(t_list	*info)
{
	while (1)
	{
		pthread_mutex_lock(&info->meals_counter_lock);
		if (info->number_of_times_each_philosopher_must_eat > 0 && info->done_eating >= \
			info->number_of_philosophers)
		{
			pthread_mutex_lock(&info->death_lock);
			pthread_mutex_lock(&info->print_lock);
			printf("%lld %d HAS EATEN %d TIMES\n",(gettime() - info->born_time) , info->philo->philo_id, info->philo->meals_counter);
			pthread_mutex_unlock(&info->print_lock);
			info->death_index += 1;
			pthread_mutex_unlock(&info->death_lock);
			return ;
		}
		pthread_mutex_unlock(&info->meals_counter_lock);
		if (gettime() - info->philo->last_meal >= info->time_to_die)
		{
			pthread_mutex_lock(&info->death_lock);
			pthread_mutex_lock(&info->print_lock);
			printf("%lld %d died\n",(gettime() - info->born_time) , info->philo->philo_id);
			pthread_mutex_unlock(&info->print_lock);
			info->death_index += 1;
			pthread_mutex_unlock(&info->death_lock);
			return ;
		}
	}
}