/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:09:57 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/01/14 15:15:44 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	check(char str)
{
	if (str == ' ' || str == '\t'
		|| str == '\n' || str == '\v'
		|| str == '\r' || str == '\f')
	{
		return (1);
	}
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	nb;
	int	i;
	int	sign;

	nb = 0;
	i = 0;
	sign = 1;
	while (check(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = str[i] - '0' + nb * 10;
		i++;
	}
	return (sign * nb);
}

int	is_bin(char c)
{
	if (c == '0')
		return (0);
	else
		return (1);
}

int	ft_atoi_bin(char *str)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (str[i])
	{
		result *= 2;
		result = result + is_bin(str[i]);
		i++;
	}
	return (result);
}

void	ft_treat_bin(char c, int pid)
{
	int		i;
	char	base;
	char	result;

	i = 0;
	base = 0b00000001;
	while(i < 8)
	{
		result = base & c;
		if (result == 0b00000000)
		{
			kill(pid, SIGUSR1);
			// write (1,"0",1);
		}
		else
		{
			kill(pid, SIGUSR2);	
			// write (1,"1",1);
		}
		base = base << 1; 
		i++;
		usleep (100);
	}
}

// int	main (int ac, char **av)
// {
// 	int	i;
// 	int	c;

// 	i = 0;
// 	if (ac == 2)
// 	{
// 		while (av[1][i])
// 		{
// 			ft_treat_bin(av[1][i], 1);
// 			i++;
// 		}
// 	}
// 	return (1);
// }