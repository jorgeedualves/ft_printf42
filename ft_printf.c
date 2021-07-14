/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:45:08 by joeduard          #+#    #+#             */
/*   Updated: 2021/07/05 14:45:08 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void handle_types(int *len, va_list args, t_flags fl)
{
    if (fl.type == 'c')
        print_c(va_arg(args, int), len);
    if (fl.type == 's')
        print_s(va_arg(args, char *), len);
    if (fl.type == 'i' || fl.type == 'd')
        print_i_d(fl, args, len);
    if (fl.type == 'u')
        print_u(fl, args, len);
    if (fl.type == 'p')
        print_p(fl, args, len);
    if (fl.type == 'x')
        print_x(fl, args, len);
    if (fl.type == 'X')
        print_X(fl, args, len);
    if (fl.type == '%')
        print_pct(len);
}

static void get_specs(const char *format, int  *i, int *len, va_list args) 
{
    t_flags fl;
 /*   int j;
    j = 0;

    while(ft_strchr_01(ALL_FLAGS, format[*i]) && j < 19)
        fl.set[j++] = format[(*i)++];
    fl.set[j] = '\0';
*/    
    if (ft_strchr_01(CONVERSIONS, format[*i]))
    {
         fl.type = format[(*i)++];
         handle_types(len, args, fl);
    }    
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int len;
    int i;

    va_start(args, format);
    len = 0;
    i = 0;
    while (format[i] != '\0')
    {
        if (format[i] != '%')
            ft_putchar_len(format[i++], &len); // tamanho = hello %-s, name // 7
        else
        {
            i++;
            get_specs(format, &i, &len, args);
            if (len == -1)
				return (-1); // %[flags][width][.precision][size]type -> "hello" "    hello"
        }
    }
    va_end(args);
    return(len);
}

int main (void)
{
    // c - i - d - u - s

    char c = 'z';
    char *s = "Vila";
    int in = 42;
    int dec = 42;
    unsigned int ui = -300;

   
    ft_printf(" string: %s, char: %c, int: %i, decimal: %d, unsigned: %u\n\n", s, c, in, dec, ui);
   // printf("\nchar: %c, string: %s, int: %i, decimal: %d, unsigned: %u\n\n", c, s, in, dec, ui);

    return (0);
}
