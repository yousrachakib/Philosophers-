/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:28:56 by yochakib          #+#    #+#             */
/*   Updated: 2023/05/27 19:42:39 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_if_died(t_list	*info)
{
	while (1)
	{
		if (gettime() - info->philo->last_meal >= info->time_to_die)
		{
			pthread_mutex_lock(&info->death_lock);
			pthread_mutex_lock(&info->print_lock);
			printf("%lld %d died\n",(gettime() - (info->philo->born_time.tv_sec * 1000) + (info->philo->born_time.tv_usec / 1000)) , info->philo->philo_id);
			pthread_mutex_unlock(&info->print_lock);
			info->death_index += 0;
			pthread_mutex_unlock(&info->death_lock);
			return ;
		}
	}
}