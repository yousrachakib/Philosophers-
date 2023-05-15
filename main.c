/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:57:11 by yochakib          #+#    #+#             */
/*   Updated: 2023/05/15 18:57:54 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *ptr)
{
	t_info *info;
	
	info = (t_info *)ptr;
	printf("WELL RECIEVED!\n");
	return 0;
	
}

int	main(int ac, char **av)
{
	t_info	info;
	t_philo *tmp;
	
	if (ac != 5 && ac != 6)
		return (ft_putstr_fd("Error\nfew args", 2), 0);
	fill_struct(&info, ac, av);
	check_error(&info, ac, av);
	creat_philo(&info);

}