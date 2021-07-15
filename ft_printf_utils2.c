/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:27:10 by joeduard          #+#    #+#             */
/*   Updated: 2021/07/15 16:27:10 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_x(t_flags fl, va_list args, int *len)
{
	fl.strNum = ft_int_to_hex_px(va_arg(args, unsigned long int));
	ft_putstr_len(fl.strNum, len);
}

void	print_X(t_flags fl, va_list args, int *len)
{
	fl.strNum = ft_int_to_hex_X(va_arg(args, unsigned long int));
	ft_putstr_len(fl.strNum, len);
}

void	print_pct(int *len)
{
	ft_putstr_len("%", len);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
