/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghun <sankang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:25:04 by sanghun           #+#    #+#             */
/*   Updated: 2022/06/02 01:18:21 by sanghun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	byte;
	static int				idx;

	(void)*info;
	(void)*ucontext;
	if (sig == SIGUSR1)
		byte += (0b00000001 << (7 - idx));
	idx++;
	if (idx == 8)
	{
		if (byte == '\0')
			ft_putchar_fd('\n', 1);
		ft_putchar_fd(byte, 1);
		byte = 0;
		idx = 0;
	}
}

int	main(void)
{
	struct sigaction	s_sa;

	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s_sa.sa_flags = SA_SIGINFO;
	s_sa.sa_sigaction = handler;
	sigaction(SIGUSR1, &s_sa, 0);
	sigaction(SIGUSR2, &s_sa, 0);
	while (1)
		pause();
	return (0);
}
