/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:53:40 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/01/16 19:22:34 by yait-iaz         ###   ########.fr       */
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
