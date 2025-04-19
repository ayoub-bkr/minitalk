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

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// utils.c
void		erroring(void);
int			ft_strlen(char *str);
int			ft_atoi(char *str);
void		ft_putnbr(int n);

typedef struct s_data
{
	int		i;
	int		len;
	__pid_t	pid;
}			t_data;
