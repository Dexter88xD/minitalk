/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:12:08 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/25 23:34:14 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_flag = 0;

void	reset_flag(int seg)
{
	if (seg == SIGUSR1)
		g_flag = 1;
}

int	send_message(int pid, char message)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (((message >> i) & 1) == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (ft_printf("No active process with this PID\n"), 1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (ft_printf("No active process with this PID\n"), 1);
		}
		while (!g_flag)
			;
		g_flag = 0;
		i--;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		i;
	int		pid;
	char	*message;

	if (ac != 3)
	{
		ft_printf("Provide The PID with a message please!\n");
		return (1);
	}
	else
	{
		signal(SIGUSR1, reset_flag);
		i = 0;
		pid = ft_atoi(av[1]);
		message = av[2];
		while (message[i])
		{
			if (send_message(pid, message[i]) == 1)
				return (1);
			i++;
		}
		usleep(50);
		send_message(pid, '\0');
	}
	return (0);
}
