/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 10:23:36 by aboukent          #+#    #+#             */
/*   Updated: 2025/04/19 10:23:37 by aboukent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_tracker;

void	waiting(int sig)
{
	if (sig == SIGUSR2)
		write(1, "Message received successfully! 👌\n", 36);
	else if (sig == SIGUSR1)
		g_tracker = 1;
}

void	sending(char byte, __pid_t pid)
{
	int	b;

	b = 7;
	while (b >= 0)
	{
		if ((byte >> b) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				erroring();
		}
		else if (!((byte >> b) & 1))
		{
			if (kill(pid, SIGUSR2) == -1)
				erroring();
		}
		b--;
		while (!g_tracker)
			pause();
		g_tracker = 0;	
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		c_data	data;
		
		data.j = 0;
		data.len = ft_strlen(av[2]);
		data.pid = ft_atoi(av[1]);
		if (data.pid <= 0)
			erroring();
		signal(SIGUSR1, waiting);
		signal(SIGUSR2, waiting);
		while (data.j <= data.len)
			sending(av[2][data.j++], data.pid);
	}
	else
	{
		write(2, "./client <pid> <message>\n", 25);
		exit(1);
	}
	return (0);
}