/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:24:27 by yochakib          #+#    #+#             */
/*   Updated: 2023/05/25 20:07:54 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_if_numbers_valid(int ac, char **av)
{
	if (!ft_isdigit(av[1]) || !ft_isdigit(av[2]) || \
		!ft_isdigit(av[3]) || !ft_isdigit(av[4]))
	{
		ft_putstr_fd("Error\nNon digit characters!", 2);
		return (0);
	}
	if (ac == 6)
	{
		if (!ft_isdigit(av[5]))
		{
			ft_putstr_fd("Error\nNon digit characters!", 2);
			return (0);
		}
	}
	return (1);
}

int	check_error(t_list *info, int ac, char **av)
{
	if (!check_if_numbers_valid(ac, av))
		return (ft_putstr_fd("Error", 2), 0);
	if (ac == 6 && info->number_of_times_each_philosopher_must_eat <= 0)
		return (ft_putstr_fd("Error\nav[5]", 2), 0);
	if (info->number_of_philosophers < 1 || info->number_of_philosophers > 200)
		return (ft_putstr_fd("Error\nav[1]", 2), 0);
	if (info->time_to_die < 60)
		return (ft_putstr_fd("Error\nav[2]", 2), 0);
	if (info->time_to_eat < 60)
		return (ft_putstr_fd("Error\nav[3]", 2), 0);
	if (info->time_to_sleep < 60)
		return (ft_putstr_fd("Error\nav[4]", 2), 0);
	return (1);
}
