/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghunka <sanghunka@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 22:53:35 by sanghunka         #+#    #+#             */
/*   Updated: 2022/04/27 00:41:09 by sanghunka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	__getlen(unsigned long long n, int base)
{
	int					len;
	unsigned long long	quotient;

	len = 1;
	quotient = n;
	while (1)
	{
		quotient = quotient / base;
		if (quotient == 0)
			break ;
		len++;
	}
	return (len);
}

char	*ft_utoa_base(unsigned long long n, char type)
{
	char				*s;
	char				*char_sets;
	int					i;
	int					base;

	base = 16;
	char_sets = "0123456789abcdef";
	if (type == 'u')
		base = 10;
	if (type == 'X')
		char_sets = "0123456789ABCDEF";
	i = __getlen(n, base);
	s = (char *)ft_calloc((i + 1), sizeof(char));
	if (!s)
		return (NULL);
	while (i--)
	{
		s[i] = (char_sets)[n % base];
		n /= base;
	}
	return (s);
}

int	print_type(char type, va_list ap)
{
	if (type == 'c')
		return (ft_printf_char(va_arg(ap, int)));
	else if (type == 's')
		return (ft_printf_str(va_arg(ap, char *)));
	else if (type == 'p')
		return (ft_printf_ptr(va_arg(ap, unsigned long long)));
	else if (type == 'd' || type == 'i')
		return (ft_printf_nbr_signed(va_arg(ap, int)));
	else if (type == 'u' || type == 'x' || type == 'X')
		return (ft_printf_nbr_unsigned(va_arg(ap, unsigned int), type));
	else if (type == '%')
		return (ft_printf_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		cnt;
	va_list	ap;

	cnt = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			cnt += print_type(*format, ap);
			format++;
		}
		else
		{
			write(1, format, 1);
			format++;
			cnt++;
		}
	}
	va_end(ap);
	return (cnt);
}
