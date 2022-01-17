/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:52:13 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/01/17 17:52:22 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_feedback(int sig)
{
	if (sig == SIGUSR1)
	{
		usleep(600);
		write(1, "the server receive the message", 30);
	}
}

int	main(int ac, char *av[])
{
	int					i;
	struct sigaction	sac;
	int					pid;

	if (ac > 2)
	{
		i = 0;
		sac.sa_handler = &ft_feedback;
		pid = ft_atoi(av[1]);
		sigaction(SIGUSR1, &sac, NULL);
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
