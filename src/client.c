/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:12:08 by sohamdan          #+#    #+#             */
/*   Updated: 2025/03/17 17:24:07 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_flag = 0;

void	reset_flag(int seg)
{
	if (seg == SIGUSR1)
		g_flag = 1;
	else if (seg == SIGUSR2)
	{
		write(2, "The server is busy!\n", 20);
		exit(1);
	}
}

void	check_if_integer(char *input)
{
	int	i;

	i = 0;
	if (input[0] == '-' || input[0] == '\0')
	{
		ft_printf("Please provide a valid PID\n");
		exit(EXIT_FAILURE);
	}
	while (input[i])
	{
		if (input[i] < '0' || input[i] > '9')
		{
			ft_printf("Please provide a valid PID\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
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
		return (ft_printf("Provide The PID with a message please!\n"), 1);
	else
	{
		signal(SIGUSR1, reset_flag);
		signal(SIGUSR2, reset_flag);
		i = 0;
		check_if_integer(av[1]);
		pid = ft_atoi(av[1]);
		if (pid <= 0)
			return (ft_printf("Please provide a valid PID\n"), 1);
		message = av[2];
		while (message[i])
		{
			if (send_message(pid, message[i]) == 1)
				return (1);
			i++;
		}
		send_message(pid, '\0');
	}
	return (0);
}
