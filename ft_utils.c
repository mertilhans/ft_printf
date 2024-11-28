/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merilhan <merilhan@42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 07:31:16 by merilhan          #+#    #+#             */
/*   Updated: 2024/11/28 07:32:07 by merilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	while (str[i])
		if (ft_print_char(str[i++]) == -1)
			return (-1);
	return (i);
}

int	ft_print_hex(unsigned long nbr, char format, int len)
{
	char	digit;

	if (nbr == 0 && len >= 0)
	{
		len += ft_print_char('0');
		return (len);
	}
	if (format == 'p')
	{
		len += ft_print_string("0x");
	}
	if (nbr > 0)
	{
		if (nbr >= 16)
		{
			len = ft_print_hex(nbr / 16, format, len);
		}
		if (format == 'x' || format == 'p')
			digit = "0123456789abcdef"[nbr % 16];
		else
			digit = "0123456789ABCDEF"[nbr % 16];
		len += ft_print_char(digit);
	}
	return (len);
}

int	ft_print_integer(long nbr, int len)
{
	if (nbr == 0 && len >= 0)
	{
		len += ft_print_char('0');
		return (len);
	}
	if (nbr < 0)
	{
		len += ft_print_char('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		len = ft_print_integer(nbr / 10, len);
	}
	len += ft_print_char("0123456789"[nbr % 10]);
	return (len);
}
