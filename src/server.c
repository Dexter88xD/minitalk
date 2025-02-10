/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:19:15 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/10 21:20:15 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include "libft.h"

void	print_it_out(int seg, siginfo_t *info, void *nothing)
{
	static char	word = 0;
	static int	counter = 0;

	word = word << 1;
	if (seg == SIGUSR2)
		word |= 1;
	counter++;
	if (counter == 8)
	{
		if (word)
			write(STDOUT_FILENO, &word, 1);
		else
			write(STDOUT_FILENO, "\n", 1);
		word = 0;
		counter = 0;
	}
	if (info->si_pid > 0)
		kill(info->si_pid, SIGUSR1);
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
