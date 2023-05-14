/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:57:11 by yochakib          #+#    #+#             */
/*   Updated: 2023/05/14 18:17:55 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_info	info;
	t_philo *tmp;
	
	if (ac != 5 && ac != 6)
		return (ft_putstr_fd("Error\nfew args", 2), 0);
	fill_struct(&info, ac, av);
	check_error(&info, ac, av);
	creat_philo(&info);
	int i = 1;
	tmp = info.philo;
	while (info.philo)
	{
		printf("====>%d\n", info.philo->philo_id);
		info.philo = info.philo->next;
		if (info.philo == tmp)
			break;
	}
}