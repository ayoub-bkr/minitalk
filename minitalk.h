/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:46:26 by aboukent          #+#    #+#             */
/*   Updated: 2025/04/17 19:46:28 by aboukent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
int	ft_atoi(char *str);
void	ft_putnbr(int n);
// struct sigaction {
// 	void     (*sa_handler)(int);
// 	void     (*sa_sigaction)(int, siginfo_t *, void *);
// 	sigset_t   sa_mask;
// 	int        sa_flags;
// 	void     (*sa_restorer)(void);
// };
