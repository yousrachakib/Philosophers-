 #ifndef PHILOSOPHERS_H
 #define PHILOSOPHERS_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct t_info
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int number_of_times_each_philosopher_must_eat;
} t_info;


void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(char *str);
int		check_if_numbers_valid(int ac, char **av);
int		check_error(t_info *info, int ac, char **av);
int		ft_atoi(char	*str);
void	fill_struct(t_info	*info, int ac, char **av);

 #endif