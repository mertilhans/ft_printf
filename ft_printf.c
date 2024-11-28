#include "ft_printf.h"
#include <stdarg.h>

static int	ft_check(char type)
{
	if (type == 'c' || type == 's' || type == 'p' || type == 'd' || type == 'i'
		|| type == 'u' || type == 'x' || type == 'X' || type == '%')
		return (1);
	return (0);
}

static int  ft_format(va_list argv, char format)
{
    if (format == 'c')
        return(ft_print_char(va_arg(argv, int)));
    else if ( format == 's')
        return(ft_print_string(va_arg(argv,char *)));
    else if (format == 'p')
        return(ft_print_hex(va_arg(argv,unsigned long),format , 0));
    else if (format == 'd' || format == 'i')
        return(ft_print_integer(va_arg(argv, int), 0));
    else if (format == 'u')
        return(ft_print_integer(va_arg(argv, unsigned int), 0));
    else if (format == 'x' || format == 'X')
        return(ft_print_hex(va_arg(argv, unsigned int), format, 0));
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
int main()
{

char c = 'A';
printf("Expected: %c\n", c);        
ft_printf("Expected: %c\n", c);        


int d = 12345;
printf("Expected: %d\n", d);       
ft_printf("Expected: %d\n", d);


int i = -12345;
printf("Expected: %i\n", i);              
ft_printf("Expected: %i\n", i);         


unsigned int u = 12345;
printf("Expected: %u\n", u);              
ft_printf("Expected: %u\n", u);       


printf("Expected: %%\n");                 
ft_printf("Expected: %%\n");               


char *str = "Hello, World!";
printf("Expected: %s\n", str);             
ft_printf("Expected: %s\n", str);   


unsigned int x = 255;
printf("Expected: %x\n", x);             
ft_printf("Expected: %x\n", x);      


unsigned int X = 255;
printf("Expected: %X\n", X);              
ft_printf("Expected: %X\n", X);


void *p = &str;
printf("Expected: %p\n", p);              
ft_printf("Expected: %p\n", p);  

}