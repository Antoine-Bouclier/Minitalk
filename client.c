/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:30:56 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/26 11:04:11 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

/*
	Used to know if the server 
	received the signal
*/
static volatile sig_atomic_t	g_ser_received = 0;

void	ser_received(int sig)
{
	(void)sig;
	g_ser_received = 1;
}

void	atob(char c, int pid)
{
	int	i;
	int	j;

	i = 128;
	j = 0;
	while (j < 8)
	{
		g_ser_received = 0;
		if (c & i)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_ser_received)
			pause();
		j++;
		i /= 2;
	}
}

void	send_msg(int pid, char *msg)
{
	while (*msg)
	{
		atob(*msg, pid);
		msg++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Error: Wrong format.\n");
		exit(EXIT_FAILURE);
	}
	pid = atoi(argv[1]);
	if (kill(pid, 0) == -1)
	{
		ft_printf("Error: PID invalid!\n");
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, ser_received);
	send_msg(pid, argv[2]);
	send_msg(pid, "\n");
	return (0);
}
