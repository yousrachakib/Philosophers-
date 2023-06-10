/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 12:42:21 by yochakib          #+#    #+#             */
/*   Updated: 2023/06/10 12:42:24 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct t_philo
{
	pthread_mutex_t	fork;
	pthread_t		ph;
	int				philo_id;
	int				meals_counter;
	struct t_philo	*next;
	struct t_list	*info;
	long long		last_meal;
}	t_philo;

typedef struct t_list
{
	int				done_eating;
	long long		born_time;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	meals_counter_lock;
	pthread_mutex_t	print_lock;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				death_index;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	struct t_philo	*philo;
}	t_list;

int			ft_atoi(char	*str);
void		ft_putstr_fd(char *str, int fd);
void		ft_putchar_fd(char c, int fd);
int			check_error(t_list *info, int ac, char **av);
t_philo		*create_node(int philo_id, t_list *info);
void		addback_node(t_philo **head, t_philo *newnode);
void		*routine(void *arg);
void		*fill_struct(t_list *info, int ac, char **av);
void		creat_philo(t_list	*info);
long long	gettime(void);
void		ft_usleep(long long n);
void		print(char *str, t_philo *philo);
void		check_if_died(t_list	*info);
void		lock_forks(t_philo *philo);
void		start_eating(t_philo	*philo);
void		go_bed(t_philo	*philo);
void		now_overthink(t_philo	*philo);
#endif
