/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:33:57 by aboukent          #+#    #+#             */
/*   Updated: 2025/04/17 18:34:02 by aboukent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

__pid_t	g_old_pid = 0;

void	printer(int sig, siginfo_t *info, void *context)
{
	static int				i;
	static unsigned char	byte;
	__pid_t					pid;

	(void)context;
	pid = info->si_pid;
	if (g_old_pid != pid)
	{
		byte = 0;
		i = 0;
	}
	g_old_pid = pid;
	if (sig == SIGUSR1)
		byte = byte | (1 << (7 - i));
	i++;
	if (i == 8)
	{
		write(1, &byte, 1);
		byte = 0;
		i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	__pid_t				pid;
	struct sigaction	siga;

	pid = getpid();
	write(1, "PID = ", 6);
	ft_putnbr(pid);
	write(1, "\n", 1);
	siga.sa_sigaction = printer;
	siga.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	while (1)
		pause();
	return (0);
}
