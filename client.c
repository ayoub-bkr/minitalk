/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:45:55 by aboukent          #+#    #+#             */
/*   Updated: 2025/04/17 19:45:58 by aboukent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	waiting(int sig)
{
	if(sig == SIGUSR2)
		write(1, "Message received successfully!\n",30);
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
				exit(1);
		}
		else if (!((byte >> b) & 1))
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		b--;
		usleep(400);
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
		signal(SIGUSR2, waiting);
		while (data.j <= data.len)
			sending(av[2][data.j++], data.pid);
	}
	return (0);
}
