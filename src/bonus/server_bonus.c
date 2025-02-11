/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:19:15 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/11 13:30:43 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

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
	kill(info->si_pid, SIGUSR1);
	old_pid = info->si_pid;
	(void)nothing;
}

int	main(void)
{
	char				*sentence;
	char				*process_id;
	struct sigaction	msg;

	msg.sa_sigaction = &print_it_out;
	sigemptyset(&msg.sa_mask);
	msg.sa_flags = SA_SIGINFO;
	process_id = ft_itoa(getpid());
	sentence = ft_strjoin("Server ID: ", process_id);
	free(process_id);
	write(STDOUT_FILENO, sentence, ft_strlen(sentence));
	free(sentence);
	write(STDOUT_FILENO, "\n", 1);
	sigaction(SIGUSR1, &msg, NULL);
	sigaction(SIGUSR2, &msg, NULL);
	while (1)
		pause();
	return (0);
}
