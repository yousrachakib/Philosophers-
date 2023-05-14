/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:18:18 by yochakib          #+#    #+#             */
/*   Updated: 2023/05/14 16:50:32 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	fill_struct(t_info	*info, int ac, char **av)
{
	info->number_of_philosophers = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
}

void	creat_philo(t_info *info)
{
	info->philo = NULL;
	int i = 1;
	while (i <= info->number_of_philosophers)
		addback_node(&info->philo, create_node(i++, info));
}