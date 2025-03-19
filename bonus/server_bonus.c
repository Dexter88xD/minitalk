/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:19:15 by sohamdan          #+#    #+#             */
/*   Updated: 2025/03/19 09:25:54 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	seperate_clients(char *word, int *counter)
{
	*word = 0;
	*counter = 0;
}

void	print_it_out(int seg, siginfo_t *info, void *nothing)
{
	static char	word;
	static int	counter;
	static int	old_pid;

	if (old_pid != info->si_pid)
		seperate_clients(&word, &counter);
	word = word << 1;
	if (seg == SIGUSR2)
		word |= 1;
	counter++;
	if (counter == 8)
	{
		if (word)
			write(STDOUT_FILENO, &word, 1);
		else
		{
			write(STDOUT_FILENO, "\n", 1);
			kill(info->si_pid, SIGUSR2);
		}
		word = 0;
		counter = 0;
	}
	old_pid = info->si_pid;
	kill(info->si_pid, SIGUSR1);
	(void)nothing;
}

int	main(void)
{
	struct sigaction	msg;

	msg.sa_sigaction = &print_it_out;
	sigemptyset(&msg.sa_mask);
	msg.sa_flags = SA_SIGINFO;
	ft_printf("Server ID: %d\n", getpid());
	sigaction(SIGUSR1, &msg, NULL);
	sigaction(SIGUSR2, &msg, NULL);
	while (1)
		pause();
	return (0);
}
