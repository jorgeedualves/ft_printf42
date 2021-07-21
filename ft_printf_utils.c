/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:06:17 by joeduard          #+#    #+#             */
/*   Updated: 2021/07/08 15:06:17 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
1
void		print_c(char c, int *len, t_flags fl)
{
	if (fl.minus == 0 && fl.width == 0)
	{
		ft_putchar_len(c, len);	
	}
	else if (fl.minus == 0 && fl. width > 0)
	{
		while (fl.width-- > 1)
		{
			write(1, " ", 1);
			len++;
		}
		ft_putchar_len(c, len);
	}
	else if (fl.minus == 1)
	{
		ft_putchar_len(c, len);
		while (fl.width-- > 1)
		{
			write(1, " ", 1);
			len++;
		}
	}
}

void	print_s(char *c, int *len, t_flags fl)
{
	int size;

	size = (int)ft_strlen(c);
	if ((fl.precision == 0 && fl.width == 0) || (fl.precision >= size && fl.width <= size))
		ft_putstr_len(c, len); 
	else if (fl.precision < size && (fl.width == 0 || fl.width < size))
		while (fl.precision > 0)
		{
			write(1, &*c, 1);
			fl.precision--, len++, c++;				
		}
	else if ((fl.precision == 0 || fl.precision >= size) && fl.width > size ) //imprime espaços + string
		print_s_space_print(c, len, fl);
	else if (fl.precision < size && fl.width >= size) //imprime espaços + corta string
		print_s_space_cut(c, len, fl);
}

void	print_s_space_print(char *c, int *len, t_flags fl)
{
	int size;

	size = (int)ft_strlen(c);
	if (fl.minus == 0)
	{
		while (fl.width > size)
		{
			write(1, " ", 1);
			fl.width--, len++;
		}
		ft_putstr_len(c, len);
	}
	else
	{
		ft_putstr_len(c, len);
		while (fl.width > size)
		{
			write(1, " ", 1);
			fl.width--, len++;
		}
	}
}

void	print_s_space_cut(char *c, int *len, t_flags fl)
{
	int size;

	size = (int)ft_strlen(c);
	if(fl.minus == 0)
	{
		while (fl.width - fl.precision > 0)
		{
			write(1, " ", 1);
			fl.width--, len++;
		}
		while (fl.precision > 0)
		{
			write(1, &*c, 1);
			fl.precision--, len++, c++;				
		}
	}
	else
	{
		while (fl.precision > 0)
		{
			write(1, &*c, 1);
			fl.precision--, len++, c++;				
		}
		while (fl.width - fl.precision > 0)
		{
			write(1, " ", 1);
			fl.width--, len++;
		}
	}
}

void	print_i_d(t_flags fl, va_list args, int *len)
{
	fl.strNum = ft_itoa(va_arg(args, int));
	ft_putstr_len(fl.strNum, len);
}
