/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:10:11 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/01/16 20:12:01 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
void	ft_treat_bin(char c, int pid);
void	sigusr_handler(int sig, siginfo_t *siginfo, void *context);
int		ft_atoi_bin(char *str);
int		is_bin(char c);
void	ft_feedback(int sig);
void	ft_putnbr(int n);

void	send_byte(char byte, int pid);
void	send_message(char *str, int pid);
void	usage(void);
void	reset_data(void);
void	handler(int sig, siginfo_t *info, void *ucontext);
void	ft_putstr(char *str);

#endif