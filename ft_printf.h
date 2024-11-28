
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_print_char(int c);
int	ft_print_string(char *str);
int	ft_printf(const char *format, ...);
int	ft_print_integer(long num, int len);
int	ft_print_hex(unsigned long num, char format, int len);

#endif