/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:38:14 by yochakib          #+#    #+#             */
/*   Updated: 2023/05/27 00:07:59 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_id_died(t_list *info)
{
	int i;
	long long time;
	
	while (info->death_index == 0)
	{
		i = 1;
		if ((gettime() - info->philo->last_meal) > info->time_to_die)
		{
			pthread_mutex_lock(&info->print_lock);
			time =  (gettime() - info->philo->born_time.tv_usec);
			print("died", info->philo);
			info->death_index += 1;
			pthread_mutex_unlock(&info->print_lock);
			return (1);
		}
	}
	return (0);
}