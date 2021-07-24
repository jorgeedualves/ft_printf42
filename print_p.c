/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 11:40:31 by joeduard          #+#    #+#             */
/*   Updated: 2021/07/24 11:40:31 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p(t_flags fl, va_list args, int *len)
{
	int	size;

	fl.strNum = ft_int_to_hex_pxX(va_arg(args, unsigned long int), fl);
	size = (int)ft_strlen(fl.strNum);
	size = size + 2;
	if (fl.zero == 0 && fl.width > size)
		print_p_no_zero(fl, len, size);
	else if (fl.zero == 1 && fl.width > size)
		print_p_zero(fl, len, size);
	else
		ft_putstr_len_p(fl.strNum, len);
}

void	print_p_no_zero(t_flags fl, int *len, int size)
{
	if (fl.minus == 0)
	{
		print_space(fl, size, len);
		ft_putstr_len_p(fl.strNum, len);
	}
	else if (fl.minus == 1)
	{
		ft_putstr_len_p(fl.strNum, len);
		print_space(fl, size, len);
	}
}

void	print_p_zero(t_flags fl, int *len, int size)
{
	if (fl.minus == 0)
	{
		write(1, "0x", 2);
		while (fl.width - size > 0)
		{
			write(1, "0", 1);
			fl.width--, len++;
		}
		ft_putstr_len(fl.strNum, len);
	}
	else if (fl.minus == 1)
	{
		ft_putstr_len_p(fl.strNum, len);
		print_space(fl, size, len);
	}
}

void	ft_putstr_len_p(char *s, int *len)
{
	int	i;

	write(1, "0x", 2);
	if (s != NULL)
	{
		i = 0;
		while (s[i])
			ft_putchar_len(s[i++], len);
	}
}
