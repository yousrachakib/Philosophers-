/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:24:27 by yochakib          #+#    #+#             */
/*   Updated: 2023/05/12 18:41:30 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isdigit(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' || str[i] <= '9')
			return (0);
		i++;
	}
	return (1);
}

void	check_arg(int ac, char **av)
{
	
}
