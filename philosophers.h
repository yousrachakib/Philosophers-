 #ifndef PHILOSOPHERS_H
 #define PHILOSOPHERS_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct t_philo
{
	pthread_t	ph;
	int philo_id;
	struct t_info	*info;
	pthread_mutex_t fork;
	struct t_philo *next;
	struct timeval	born_time;
}				t_philo;

typedef struct t_info
{
	pthread_mutex_t	print;
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int number_of_times_each_philosopher_must_eat;
	struct t_philo *philo;
}		t_info;

size_t 	gettime(t_philo	*philo);
void	*routine(void *ptr);
void	creat_philo(t_info *info);
t_philo	*create_node(int	philo_id, t_info *info);
void	addback_node(t_philo **head, t_philo *newnode);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(char *str);
int		check_if_numbers_valid(int ac, char **av);
int		check_error(t_info *info, int ac, char **av);
int		ft_atoi(char	*str);
void	fill_struct(t_info	*info, int ac, char **av);

 #endif