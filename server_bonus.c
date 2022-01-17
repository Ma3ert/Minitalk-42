/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:52:34 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/01/17 17:54:43 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_pid1;

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
	static int	i;
	char		c;
	int			check;

	if (g_pid1 != siginfo->si_pid)
		i = 7;
	check = 0;
	context = NULL;
	if (sig == SIGUSR1 && i >= 0)
		str[i] = '0';
	else if (sig == SIGUSR2 && i >= 0)
		str[i] = '1';
	if (i == 0)
	{
		c = ft_atoi_bin(str);
		write(1, &c, 1);
		if (c == 0)
			check = 1;
		i = 8;
	}
	i--;
	if (check == 1 && siginfo->si_pid != 0)
		kill(siginfo->si_pid, SIGUSR1);
	g_pid1 = siginfo->si_pid;
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;
	static int			i;

	i = 0;
	pid = getpid();
	write(1, "server PID: ", 12);
	ft_putnbr(pid);
	ft_putchar('\n');
	sa.sa_sigaction = &sigusr_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
		pause();
}
