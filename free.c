/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 20:38:14 by yochakib          #+#    #+#             */
/*   Updated: 2023/06/01 21:21:48 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void freelist(t_philo *head) 
{
    t_philo *current = head;
    t_philo *next;
    
    while (current)
    {
        next = current->next;
        free(current);
        pthread_mutex_destroy(&current->fork);
        current = next;
    }
}
