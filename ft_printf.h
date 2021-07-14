/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:35:17 by joeduard          #+#    #+#             */
/*   Updated: 2021/07/06 20:35:17 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "stdlib.h"
# include "string.h"


# define CONVERSIONS	"cspdiuxX%"
# define ALL_FLAGS "-0.*0123456789cspdiuxX%"
# define NUMBERS		"0123456789"

typedef struct 
{
    char    type;
    char    *strNum;
    int     width;
    int     precision;
    char    *set[20];
} t_flags;

int     ft_printf(const char *format, ...);
void	ft_putchar_len(char c, int *len);
int		ft_strchr_01(char *s, char c);

//para imprimir integer:
size_t	ft_strlen(const char *s);
void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_putnbr(int n);
char	*ft_itoa(int n);
void	ft_putstr_len(char *s, int *len);
void	print_s(char *c, int *len);
void    print_i_d(t_flags fl, va_list args, int *len);

void    print_u(t_flags fl, va_list args, int *len);
char	*ft_uitoa(unsigned int n);
int 	ft_ulen(unsigned int num);
void	print_c(char c, int *len);


#endif