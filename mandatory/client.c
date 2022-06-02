/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghun <sankang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:31:49 by sanghun           #+#    #+#             */
/*   Updated: 2022/06/02 01:18:30 by sanghun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(int pid, char c)
{
	unsigned char	bitmask;

	bitmask = 0b10000000;
	while (bitmask > 0)
	{
		if ((c & bitmask) == bitmask)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bitmask = bitmask >> 1;
		usleep(1000);
	}
}

void	send_str(int pid, char *str)
{
	while (*str)
		send_bit(pid, *(str++));
	send_bit(pid, '\0');
}

int	main(int argc, char *argv[])
{
	if (argc != 3 || !ft_strlen(argv[2]))
		ft_putstr_fd("USAGE: ./client <PID> <STR>", 1);
	else
		send_str(ft_atoi(argv[1]), argv[2]);
	return (0);
}
