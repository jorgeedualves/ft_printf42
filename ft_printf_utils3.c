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

int		ft_len_hex(unsigned long int x)
{
	int len;
	
	len  = 0;
	while (x)
	{
		x = x / 16;
		len++;
	}
	return (len);
}

char	*ft_int_to_hex_pxX(unsigned long int n, t_flags fl)
{ 
	int len;
	char *result;
	int temp;

	len = ft_len_hex(n);
	result = (char *)malloc(len + 1);
	if (result == NULL)
		return (0);
	result[len--] = '\0';
	while (len >= 0)
	{
		temp = 0;
		temp = n % 16;
        if (temp < 10) 
            result[len--] = temp + 48;
        else 
		{
			if (fl.type == 'x' || fl.type == 'p')
            	result[len--] = temp + 87;
			else
				result[len--] = temp + 55;
		}
		n = n / 16;
    }
	return (result);	
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_len(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

int		ft_strchr(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i++] == c)
			return (1);
	}
	return (0);
}
