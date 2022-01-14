/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:10:11 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/01/14 14:14:30 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int		ft_atoi(const char *str);
void	ft_treat_bin(char c, int pid);
void	sigusr_handler(int sig);
int		ft_atoi_bin(char *str);
int		is_bin(char c);

#endif