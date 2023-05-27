/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:38:14 by yochakib          #+#    #+#             */
/*   Updated: 2023/05/27 17:22:36 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_id_died(t_list *info)
{
	int			i;
	long long	time;

	while (1)
	{
		i = 1;
		if ((gettime() - (info->philo->last_meal.tv_sec * 1000 + \
			info->philo->last_meal.tv_usec / 1000)) > info->time_to_die)
		{
			pthread_mutex_lock(&info->death_lock);
			pthread_mutex_lock(&info->print_lock);
			printf("%lld %d died", gettime(), info->philo->philo_id);
			info->death_index += 1;
			pthread_mutex_unlock(&info->print_lock);
			pthread_mutex_unlock(&info->death_lock);
			return (1);
		}
	}
	return (0);
}
