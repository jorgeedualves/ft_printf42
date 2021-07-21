/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uitls6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:22:29 by joeduard          #+#    #+#             */
/*   Updated: 2021/07/21 16:22:29 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_flags	ft_clean_flags(void)
{
	t_flags fl;

	fl.minus = 0;
	fl.zero = 0;
	fl.width = 0;
	fl.dot = 0;
	fl.precision = 0;
	return (fl);
}
