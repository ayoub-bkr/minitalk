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

void	printer(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	static int	i;
	static unsigned char byte;
	unsigned char bit;

	i = 7;
	byte = 0;
	if (sig == SIGUSR1)
	{
		bit = 1;
		byte = byte | (bit << i);
		i--;
	}
	if (i == 0)
	{
		write(1, &byte, 1);
		write(1, "\n", 1);
		byte = 0;
		i = 7;
	}
}
int	main()
{
	__pid_t	pid;
	struct sigaction siga;

	pid = getpid();
	ft_putnbr(pid);
	siga.sa_sigaction = printer;
	siga.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	while (1)
		pause();
}
