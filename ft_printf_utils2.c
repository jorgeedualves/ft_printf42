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

void 	print_u(t_flags fl, va_list args, int *len)
{
	fl.strNum = ft_uitoa(va_arg(args, unsigned int));
	ft_putstr_len(fl.strNum, len);	
}

void	print_p(t_flags fl, va_list args, int *len)
{
	fl.strNum = ft_int_to_hex_pxX(va_arg(args, unsigned long int), fl);
	ft_putstr_len_p(fl.strNum, len);
}

void	print_x(t_flags fl, va_list args, int *len)
{
	fl.strNum = ft_int_to_hex_pxX(va_arg(args, unsigned long int), fl);
	ft_putstr_len(fl.strNum, len);
}

void	print_X(t_flags fl, va_list args, int *len)
{
	fl.strNum = ft_int_to_hex_pxX(va_arg(args, unsigned long int), fl);
	ft_putstr_len(fl.strNum, len);
}

void print_pct(int *len)
{
	ft_putstr_len("%", len);
}

