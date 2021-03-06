/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:53:40 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/01/17 17:51:46 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char *av[])
{
	int					i;
	int					pid;

	if (ac == 3)
	{
		i = 0;
		pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			ft_treat_bin(av[2][i], pid);
			i++;
		}
		ft_treat_bin(av[2][i], pid);
	}
	else
		write(1, "argument error", 14);
	return (0);
}
