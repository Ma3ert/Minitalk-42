/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:12:40 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/01/12 15:12:41 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		i = 7;

void	sigusr_handler(int sig)
{
	static char	str[8];
	int		j = 0;
	char	c;

	if (sig == SIGUSR1 && i >= 0)
	{
		str[i] = '0';
		if (i == 0)
		{
			c = ft_atoi_bin(str);
			write(1, &c, 1);
			i = 8;
		}
		i--;
	}
	else if (sig == SIGUSR2 && i >= 0)
	{
		str[i] = '1';
		if (i == 0)
		{
			c = ft_atoi_bin(str);
			write(1, &c, 1);
			i = 8;
		}
		i--;
	}
}

int main(int ac, char **av)
{
	int	pid;
	struct sigaction sa;
	static int i;

	i = 0;
	pid = getpid();
	printf("%d\n", pid);
	sa.sa_handler = &sigusr_handler ;
	sa.sa_flags = SA_NODEFER ;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
		pause ();
}