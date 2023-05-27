/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:57:27 by yochakib          #+#    #+#             */
/*   Updated: 2023/05/27 15:05:10 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
	printf("done !\n");
}

int	ft_atoi(char	*str)
{
	int	i;
	int	s;
	int	r;

	i = 0;
	s = 1;
	r = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while ((str[i] == '+' || str[i] == '-' )
		&& (str[i + 1] == '+' || str[i + 1] == '-' ))
		return (0);
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		r = r * 10 + (str[i++] - 48);
	return (r * s);
}

t_philo	*create_node(int philo_id, t_list *info)
{
	t_philo	*node;

	node = malloc(sizeof(t_philo));
	if (!node)
		return (NULL);
	node->philo_id = philo_id;
	node->next = node;
	node->info = info;
	node->meals_counter = 0;
	pthread_mutex_init(&node->fork, NULL);
	return (node);
}

void	addback_node(t_philo **head, t_philo *newnode)
{
	t_philo	*tmp;

	tmp = *head;
	if (!*head)
	{
		*head = newnode;
		return ;
	}
	while (tmp)
	{
		tmp = tmp->next;
		if (tmp->next == *head)
			break ;
	}
	tmp->next = newnode;
	newnode->next = *head;
}
