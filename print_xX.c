/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 11:41:47 by joeduard          #+#    #+#             */
/*   Updated: 2021/07/24 11:41:47 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    print_xX(t_flags fl, va_list args, int *len, const char c)
{
    int    size;
		fl.ulli = va_arg(args, unsigned int);		
    if (c == 'X')
        fl.strNum = ft_ullitoa_base(fl.ulli, HEXAUPP);
    else if (c == 'x')
        fl.strNum = ft_ullitoa_base(fl.ulli, HEXALOW);
    size = (int)ft_strlen(fl.strNum);
    if ((fl.width == 0 || fl.width <= size) && (fl.precision == 0 || fl.precision <= size))
        ft_putstr_len(fl.strNum, len);
    else if ((fl.width == 0 || fl.width <= size) && (fl.precision  > size))		//(" %.10x ", LONG_MAX)
  	{
		while (fl.precision - size > 0)
		{
			write(1, "0", 1);
			fl.precision--, (*len)++;
		}
		ft_putstr_len(fl.strNum, len);
	}
    else if (fl.width > size && (fl.precision == 0 || fl.precision <= size))
    {
        if (fl.minus == 1)
        {
 	    	ft_putstr_len(fl.strNum, len);
   		   	while (fl.width - size > 0)
		    {
		  		write(1, " ", 1);
		    	fl.width--, (*len)++;
	    	}
        }
		else
		{
 	       if (fl.zero == 0)
   	    	{
   		   		while (fl.width - size > 0)
		    	{
			   		write(1, " ", 1);
			    	fl.width--, (*len)++;
		    	}
		    	ft_putstr_len(fl.strNum, len);
        	}
        	else
			{
  		    	while (fl.width - size > 0)
		    	{
			    	write(1, "0", 1);
			    	fl.width--, (*len)++;
		    	}
		   		ft_putstr_len(fl.strNum, len);      
			}
 		}
    }
    else if (fl.width > size && fl.precision > size)
    {
		if (fl.minus == 1)
		{
  			while (fl.precision - size > 0)
			{
			    write(1, "0", 1);
			    fl.precision--, (*len)++;
			}
			ft_putstr_len(fl.strNum, len);
 			while (fl.width - fl.precision > 0)
			{
				write(1, " ", 1);
				fl.width--, (*len)++;
			}
		}
		else
		{
 			while (fl.width - fl.precision > 0)
			{
				write(1, " ", 1);
				fl.width--, (*len)++;
			}
  			while (fl.precision - size > 0)
			{
			    write(1, "0", 1);
			    fl.precision--, (*len)++;
	    	}
	    	ft_putstr_len(fl.strNum, len);
		}
    }
    free(fl.strNum);
}

int	ft_len_hex(unsigned long int x)
{
	int	len;

	len = 0;
	while (x)
	{
		x = x / 16;
		len++;
	}
	return (len);
}
                         
char        *ft_ullitoa_base(unsigned long long int n, char *base)
{
    char                 	   *a;
    unsigned long long int 	   nbr;
    size_t                 	   size;
    int                        b_len;

    b_len = ft_strlen(base);
    nbr = n;
    size = 1;
    while (n /= b_len)
        size++;
    if (!(a = (char *)malloc(size + 1)))
        return (0);
    a[size--] = '\0';
    while (nbr > 0)
    {
        a[size--] = base[nbr % b_len];
        nbr /= b_len;
    }
    if (size == 0 && a[1] == '\0')
        a[0] = '0';
    return (a);
}
