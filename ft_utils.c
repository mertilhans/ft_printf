/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merilhan <merilhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 07:31:16 by merilhan          #+#    #+#             */
/*   Updated: 2024/12/03 19:22:41 by merilhan         ###   ########.fr       */
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
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
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
	if (nbr > 0)
	{
		if (nbr >= 16)
		{
			len = ft_print_hex(nbr / 16, format, len);
		}
		if (format == 'x')
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
