/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 11:34:01 by joeduard          #+#    #+#             */
/*   Updated: 2021/07/24 11:34:01 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_i_d(t_flags fl, va_list args, int *len) 
{
	int number;

	number = va_arg(args, int);
	if (number >= 0)
		print_id_positive(fl, number, len);
	else
	{
		number *= -1;
		print_id_negative(fl, number, len);
	}	
}

void	print_id_positive(t_flags fl, int number, int *len)    		// (" %.2d ", -1)
{
	int size;

	fl.strNum = ft_itoa(number);
	size = (int)ft_strlen(fl.strNum);
	if ((fl.width <= size || fl.width == 0) && (fl.precision <= size || fl.precision == 0))
		ft_putstr_len(fl.strNum, len);
	if (((fl.width == 0 || fl.width <= size) && fl.precision > size) || (fl.width > size && (fl.precision == 0 || fl.precision > size)))
	{
		if (fl.minus == 1)
		{
			ft_putstr_len(fl.strNum, len);
			print_space(fl, size, len);
		}
		if (fl.dot == 0 && fl.zero == 0)
		{
			print_space(fl, size, len);
			ft_putstr_len(fl.strNum, len);
		}
		else
		{
			print_i_d_zero(fl, size, len);
			ft_putstr_len(fl.strNum, len);
		}
	}
	if (fl.width > size && (fl.precision <= size && fl.precision != 0))
	{	
		if (fl.minus == 1)
		{
			ft_putstr_len(fl.strNum, len);
			print_space(fl, size, len);
		}
		else
		{
			print_space(fl, size, len);
			ft_putstr_len(fl.strNum, len);
		}
	}
	free(fl.strNum);
}

void	print_id_negative(t_flags fl, int number, int *len) // 	printf(" %.2d ", -1);
{
	int size;
	if (number == -2147483648)
		fl.strNum = "2147483648";
	else
		fl.strNum = ft_itoa(number);
	size = (int)ft_strlen(fl.strNum) + 1; //pra compensar o sinal negativo que tiramos
	if (fl.width <= size && fl.precision < size)
	{
		ft_putchar_len('-', len);
		ft_putstr_len(fl.strNum, len);
	}
	if (fl.precision > size -1)
	{
		ft_putchar_len('-', len);
		while (fl.precision - (size - 1) > 0)
		{
			write(1, "0", 1);
			fl.precision--, (*len)++;
		}
		ft_putstr_len(fl.strNum, len);
	}
	if ((fl.width > size || fl.width == 0) && (fl.precision == 0 || fl.precision > size) && fl.zero == 1)
	{
		ft_putchar_len('-', len);
		print_i_d_zero(fl, size, len);
		ft_putstr_len(fl.strNum, len);
	}
	if ((fl.width > size && fl.precision != 0) && fl.precision <= size )
	{	
		if (fl.minus == 1)
		{
			ft_putchar_len('-', len);
			ft_putstr_len(fl.strNum, len);
			print_space(fl, size, len);
		}
		else
		{
			print_space(fl, size, len);
			ft_putchar_len('-', len);
			ft_putstr_len(fl.strNum, len);
		}
	}
	if (fl.minus == 1 && fl.precision == 0 && fl.width > size)
	{
		ft_putchar_len('-', len);
		ft_putstr_len(fl.strNum, len);
		print_space(fl, size, len);
	}
	if (number != -2147483648)
		free(fl.strNum);
}

void	print_space(t_flags fl, int size, int *len)
{
	if (fl.precision > 0)
	{
		while (fl.precision - size > 0)
		{
			write(1, "0", 1);
			fl.precision--, (*len)++;
		}
	}
	else
	{
		while (fl.width - size > 0)
		{
			write(1, " ", 1);
			fl.width--, (*len)++;
		}
	}
}

void	print_i_d_zero(t_flags fl, int size, int *len)
{
	if (fl.precision > 0)
	{
		while (fl.precision - size > 0)
		{
			write(1, "0", 1);
			fl.precision--, (*len)++;
		}
	}
	else								// imprime zeros quando o width > zero
	{		
		while (fl.width - size > 0)
		{
			write(1, "0", 1);
			fl.width--, (*len)++;
		}
	}
}
