/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghunka <sanghunka@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:58:56 by sanghunka         #+#    #+#             */
/*   Updated: 2022/04/27 00:41:04 by sanghunka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_printf_str(char *s)
{
	if (!s)
		s = "(null)";
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	ft_printf_nbr_signed(int n)
{
	int		cnt;
	char	*s;

	s = ft_itoa(n);
	cnt = ft_printf_str(s);
	free(s);
	return (cnt);
}

int	ft_printf_nbr_unsigned(unsigned int n, char type)
{
	int		cnt;
	char	*s;

	s = ft_utoa_base(n, type);
	cnt = ft_printf_str(s);
	free(s);
	return (cnt);
}

int	ft_printf_ptr(unsigned long long n)
{
	int		cnt;
	char	*s;

	cnt = ft_printf_str("0x");
	s = ft_utoa_base(n, 'p');
	cnt += ft_printf_str(s);
	free(s);
	return (cnt);
}
