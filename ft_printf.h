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
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

# define CONVERSIONS	"cspdiuxX%"
# define ALL_FLAGS "-0.*0123456789cspdiuxX%"
# define NUMBERS "123456789"

typedef struct {
    char type;
    int width;
    int precision;
} t_flags;

int ft_printf(const char *format, ...);
void	ft_putchar_len(char c, int *len);
int		ft_strchr_01(char *s, char c);
void		print_spec_c(int *len, t_flags fl, char c);

#endif