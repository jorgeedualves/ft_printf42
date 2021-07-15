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
# define CONVERSIONS    "cspdiuxX%"
# define ALL_FLAGS      "-0.0123456789cspdiuxX%"
# define NUMBERS        "0123456789"

typedef struct t_flags
{
	char		type;
	char		*strNum;
	int			width;
	int			precision;
}	t_flags;

int		ft_printf(const char *format, ...);
void	print_c(char c, int *len);
void	print_s(char *c, int *len);
void	print_i_d(t_flags fl, va_list args, int *len);
void	print_u(t_flags fl, va_list args, int *len);
void	print_p(t_flags fl, va_list args, int *len);
void	print_x(t_flags fl, va_list args, int *len);
void	print_X(t_flags fl, va_list args, int *len);
void	print_pct(int *len);
void	ft_putchar_len(char c, int *len);
int		ft_strchr_01(char *s, char c);
size_t	ft_strlen(const char *s);
void	ft_putstr(char *s);
void	ft_putstr_len(char *s, int *len);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
void	ft_putstr_len_p(char *s, int *len);
int		len_hex(unsigned long int x);
int		ft_len(int num);
int		ft_ulen(unsigned int num);
int		ft_to_positive(int num);
char	*ft_int_to_hex_px(unsigned long int n, t_flags fl);

#endif
