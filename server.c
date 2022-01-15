/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:12:40 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/01/15 21:16:28 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_i = 7;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
	{
		ft_putchar(num + '0');
	}
}

void	sigusr_handler(int sig, siginfo_t *siginfo, void *context)
{
	static char	str[8];
	int			j;
	char		c;
	int			check;

	j = 0;
	check = 0;
	context = NULL;
	if (sig == SIGUSR1 && g_i >= 0)
		str[g_i] = '0';
	else if (sig == SIGUSR2 && g_i >= 0)
		str[g_i] = '1';
	if (g_i == 0)
	{
		c = ft_atoi_bin(str);
		write(1, &c, 1);
		if (c == 0)
			check = 1;
		g_i = 8;
	}
	g_i--;
	if (check == 1 && siginfo->si_pid != 0)
		kill(siginfo->si_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;
	static int			i;

	i = 0;
	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	sa.sa_sigaction = &sigusr_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
		pause();
}
