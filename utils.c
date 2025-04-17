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

int     ft_atoi(const char *nptr)
{
	int     i;
	int     sign;
	int     result;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
	i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
	if (nptr[i] == '-')
			sign *= -1;
	i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
	result *= 10;
	result += (nptr[i++] - 48);
	}
	return (result * sign);
}
