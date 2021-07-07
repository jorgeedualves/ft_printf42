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

static int handle_flags_and_types(const char *format, int *i, int len)
{
    // se format for '-' -> alinhar à esquerda
    if (format[*i] == '-')
        ft_strtrim(format[*i], ' '); //hello
    else if (format[*i] == '0' && NUMBERS) // -0.*cspdiuxX%
    {
        
    }
}

static int flags_and_types_identifier(const char *format, int *i, int len)
{
    // conta todos os tipos e flags e retorna a impressão correta e o len
    if (format[*i] != '%')
    {
       while (ft_strchr(FLAGS_AND_TYPES, format[*i]))
        {
            // chama funcao para tratar as flags
            len = handle_flags_and_types(format[*i], len);
        }
    }
    return (len);
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
        {
            ft_putchar_len(format[i], len); // tamanho = hello %-s, name // 7
            i++;
            len++;
        }
        else
        {
            i++;
            flags_and_types_identifier(format, &i, len);  // %[flags][width][.precision][size]type -> "hello" "    hello"
        }
    }
    va_end(args);
    return(len);
}

int main(void)
{
    ft_printf("Hello World!");
}

// if (format[*i] != '%') // 

// gera_flags(format, &i, tamanho, args); //