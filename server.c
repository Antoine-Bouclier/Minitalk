/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:38:46 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/26 16:48:51 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

/**
 * @brief Adds a character to the message.
 * 
 * Allocates memory for a new message, appends
 * the character, and frees the old message.
 * 
 * @param old_message Existing message (can be NULL).
 * @param c Character to add.
 * @param len Pointer to the current message length.
 * @return char* Updated message.
 */
static char	*update_message(char *old_message, char c, int *len)
{
	char	*new_message;

	new_message = malloc(*len + 2);
	if (!new_message)
	{
		ft_printf("Error! Memory allocation failed.\n");
		free(old_message);
		exit(EXIT_FAILURE);
	}
	if (old_message)
	{
		ft_memcpy(new_message, old_message, *len);
		free(old_message);
	}
	new_message[*len] = c;
	new_message[*len + 1] = '\0';
	(*len)++;
	return (new_message);
}

/**
 * @brief Handles SIGUSR1 and SIGUSR2 signals.
 * 
 * Reconstructs the message bit by bit 
 * and sends an acknowledgment signal.
 * 
 * @param sig Signal received.
 * @param info Signal information.
 * @param context Signal context (unused).
 */
static void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static char	c = 0;
	static char	*message = NULL;
	static int	len = 0;

	(void)context;
	if (sig == SIGUSR1)
		c |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			ft_printf("%s", message);
			free(message);
			message = NULL;
			len = 0;
		}
		else
			message = update_message(message, c, &len);
		bit = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

/**
 * @brief Server main function.
 * 
 * Sets up signal handlers and waits
 * for signals in an infinite loop.
 * 
 */
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
