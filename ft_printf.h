/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merilhan <merilhan@42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 07:31:03 by merilhan          #+#    #+#             */
/*   Updated: 2024/11/28 07:31:05 by merilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_print_char(int c);
int	ft_print_string(char *str);
int	ft_printf(const char *format, ...);
int	ft_print_integer(long num, int len);
int	ft_print_hex(unsigned long num, char format, int len);

#endif