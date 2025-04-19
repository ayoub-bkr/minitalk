/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:13:31 by aboukent          #+#    #+#             */
/*   Updated: 2025/04/17 20:13:33 by aboukent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	erroring(void)
{
	write(2, "Error! Invalid pid !\n", 21);
	exit(1);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32 || str[i] == '0')
	i++;
	if (str[i] == '-' || str[i] == '+')
	{
	if (str[i] == '-')
			sign *= -1;
	i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += (str[i++] - 48);
		if (result > 2147483647)
			erroring();
	}
	if (str[i])
		erroring();
	return ((int)result * sign);
}

void	ft_putnbr(int n)
{
	int	nb;

	nb = n + 48;
	if (n == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2147483648", 10);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(n * -1);
	}
	else if (n >= 0 && n <= 9)
		write(1, &nb, 1);
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
