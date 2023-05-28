/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:28:56 by yochakib          #+#    #+#             */
/*   Updated: 2023/05/28 18:41:40 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_if_died(t_list	*info)
{
	while (1)
	{
		if (gettime() - info->philo->last_meal >= info->time_to_die)
		{
			// printf("%lld - %lld >= %d\n",gettime(), info->philo->last_meal, info->time_to_die);
			pthread_mutex_lock(&info->death_lock);
			pthread_mutex_lock(&info->print_lock);
			printf("%lld %d died\n",(gettime() - info->born_time) , info->philo->philo_id);
			// printf("%ld * 1000 + %d \n", info->philo->born_time.tv_sec, info->philo->born_time.tv_usec);
			// usleep(200);
			pthread_mutex_unlock(&info->print_lock);
			info->death_index += 0;
			pthread_mutex_unlock(&info->death_lock);
			return ;
		}
	}
}