/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:08:21 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/26 15:36:56 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(unsigned int pid)
{
	if (pid > 9)
		ft_putnbr(pid / 10);
	write(1, &"0123456789"[pid % 10], 1);
}
