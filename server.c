/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:38:46 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/26 12:18:10 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

#define BUFFER_SIZE 1024

static void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static char	c = 0;
	static char buffer[BUFFER_SIZE];
	static int	index = 0;

	(void)context;
	if (sig == SIGUSR1)
		c |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			buffer[index] = '\0';
			ft_printf("%s", buffer);
			index = 0;
		}
		else if (index < BUFFER_SIZE - 1)
		{
			buffer[index++] = c;
			if (c == '\n')
			{
				buffer[index] = '\0';
				ft_printf("%s", buffer);
				index = 0;
			}
		}
		bit = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}


