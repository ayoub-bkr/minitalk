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

int	main(int ac, char **av)
{
	__pid_t	pid = ft_atoi(av[1]);
	int	i = 7;
	unsigned char	byte;
	byte = 2;
	while (i >= 0)
	{
		if ((byte >> i) & 1)
			kill(pid, SIGUSR1);
		else if (!((byte >> i) & 1))
			kill(pid, SIGUSR2);
		i--;
		usleep(100);
	}
}