/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:30:56 by abouclie          #+#    #+#             */
/*   Updated: 2025/01/23 12:41:22 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "minitalk.h"

void    char_to_binary2(char c, char *binary)
{
    int i;
    int j;

    i = 128;
    j = 0;
    while (j < 8)
    {
        binary[j] = (c & i) ? '1' : '0';
        j++;
        i /= 2;
    }
    binary[8] = '\0';
}

void    send_msg(int pid, char *msg)
{
    char    binary[9];
    int     i;

    while (*msg)
	{
        i = 0;
        printf("Sending char: %c\n", *msg);
		char_to_binary2(*msg, binary);
        printf("Binary: %s\n", binary);
        while (i < 8)
        {
            if (binary[i] == '1')
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            usleep(500);
            i++;
        }
		msg++;
	}
}


int main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		exit(write(1, "Error: Wrong format.", 20));
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
			exit(write(1, "ERROR: PID invalid!\n", 20));
		i++;
	}
	send_msg(ft_atoi(argv[1]), argv[2]);
	send_msg(ft_atoi(argv[1]), "\n");
	if (argv[1][i] == '\0')
		write(1, "Message sent!\n", 14);
	return (0);
}