/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:31:00 by joeduard          #+#    #+#             */
/*   Updated: 2021/07/15 16:31:00 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_clean_flags(void)
{
	t_flags	fl;

	fl.minus = 0;
	fl.zero = 0;
	fl.width = 0;
	fl.dot = 0;
	fl.precision = 0;
	return (fl);
}

void	ft_putstr_len(char *s, int *len)
{
	int	i;

	if (s != NULL)
	{
		i = 0;
		while (s[i])
			ft_putchar_len(s[i++], len);
	}
}

void	print_pct(int *len)
{
	ft_putstr_len("%", len);
}
