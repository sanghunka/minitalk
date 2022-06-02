/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghunka <sankang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:31:49 by sanghun           #+#    #+#             */
/*   Updated: 2022/06/03 00:29:24 by sanghunka        ###   ########.fr       */
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

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static int	cnt;

	(void)*info;
	(void)*ucontext;
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("1 bit received. Total ", 1);
		ft_putnbr_fd(++cnt, 1);
		ft_putstr_fd("bit received", 1);
		ft_putchar_fd('\n', 1);
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	s_sa;

	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_putstr_fd("USAGE: ./client <PID> <STR>", 1);
		return (0);
	}
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s_sa.sa_flags = SA_SIGINFO;
	s_sa.sa_sigaction = handler;
	sigaction(SIGUSR1, &s_sa, 0);
	send_str(ft_atoi(argv[1]), argv[2]);
	return (0);
}
