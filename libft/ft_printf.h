/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghun <sankang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 22:53:33 by sanghunka         #+#    #+#             */
/*   Updated: 2022/06/01 16:54:40 by sanghun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int		ft_printf_char(int c);
int		ft_printf_str(char *s);
int		ft_printf_nbr_signed(int n);
int		ft_printf_nbr_unsigned(unsigned int n, char type);
int		ft_printf_ptr(unsigned long long n);

char	*ft_utoa_base(unsigned long long n, char type);
int		print_type(char type, va_list ap);
int		ft_printf(const char *format, ...);

#endif