/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 21:59:24 by yochakib          #+#    #+#             */
/*   Updated: 2023/06/01 19:32:53 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	lock_forks(t_philo *philo)
{
	if (philo->info->death_index)
		return ;
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->info->print_lock);
	print("has taken a fork\n", philo);
	pthread_mutex_unlock(&philo->info->print_lock);
	pthread_mutex_lock(&philo->next->fork);
	pthread_mutex_lock(&philo->info->print_lock);
	print(" has taken a fork\n", philo);
	pthread_mutex_unlock(&philo->info->print_lock);
}

void	start_eating(t_philo	*philo)
{
	if (philo->info->death_index)
		return ;
	pthread_mutex_lock(&philo->info->print_lock);
	print("is eating\n", philo);
	philo->meals_counter += 1;
	if (philo->meals_counter > \
		philo->info->number_of_times_each_philosopher_must_eat)
		philo->info->done_eating++;
	pthread_mutex_unlock(&philo->info->print_lock);
	ft_usleep(philo->info->time_to_eat);
	philo->last_meal = gettime();
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

void	go_bed(t_philo	*philo)
{
	if (philo->info->death_index)
		return ;	
	pthread_mutex_lock(&philo->info->print_lock);
	print("is sleeping\n", philo);
	pthread_mutex_unlock(&philo->info->print_lock);
	ft_usleep(philo->info->time_to_sleep);		
}

void	now_overthink(t_philo	*philo)
{
	if (philo->info->death_index)
		return ;
	pthread_mutex_lock(&philo->info->print_lock);
	print("is thinking\n", philo);
	pthread_mutex_unlock(&philo->info->print_lock);
}
