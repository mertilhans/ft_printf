/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merilhan <merilhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 07:31:03 by merilhan          #+#    #+#             */
/*   Updated: 2024/12/03 19:22:45 by merilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_print_char(int c);
int	ft_print_string(char *str);
int	ft_printf(const char *format, ...);
int	ft_print_integer(long num, int len);
int	ft_print_hex(unsigned long num, char format, int len);
int	ft_putptr(unsigned long n);
#endif