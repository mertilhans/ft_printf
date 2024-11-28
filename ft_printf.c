/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merilhan <merilhan@42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 07:30:44 by merilhan          #+#    #+#             */
/*   Updated: 2024/11/28 07:31:07 by merilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_check(char type)
{
	if (type == 'c' || type == 's' || type == 'p' || type == 'd' || type == 'i'
		|| type == 'u' || type == 'x' || type == 'X' || type == '%')
		return (1);
	return (0);
}

static int	ft_format(va_list argv, char format)
{
	if (format == 'c')
		return (ft_print_char(va_arg(argv, int)));
	else if (format == 's')
		return (ft_print_string(va_arg(argv, char *)));
	else if (format == 'p')
		return (ft_print_hex(va_arg(argv, unsigned long), format, 0));
	else if (format == 'd' || format == 'i')
		return (ft_print_integer(va_arg(argv, int), 0));
	else if (format == 'u')
		return (ft_print_integer(va_arg(argv, unsigned int), 0));
	else if (format == 'x' || format == 'X')
		return (ft_print_hex(va_arg(argv, unsigned int), format, 0));
	else if (format == '%')
		return (ft_print_char('%'));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	argv;
	int		len;
	int		i;
	int		tmp;

	len = 0;
	i = -1;
	va_start(argv, format);
	while (format[++i])
	{
		if (format[i] == '%' && ft_check(format[i + 1]))
		{
			tmp = ft_format(argv, format[++i]);
			if (tmp == -1)
				return (-1);
			len += tmp;
		}
		else if (format[i] != '%' && ft_print_char(format[i]) == -1)
			return (-1);
		else if (format[i] != '%')
			len++;
	}
	va_end(argv);
	return (len);
}
