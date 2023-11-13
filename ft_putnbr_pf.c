/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:02:29 by gdel-val          #+#    #+#             */
/*   Updated: 2023/11/03 20:21:17 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_pf(int num, size_t *counter)
{
	char	c;

	if (num == -2147483648)
		(*counter) += write(1, "-2147483648", 11);
	else
	{
		if (num < 0)
		{
			(*counter) += write(1, "-", 1);
			num = -num;
		}
		if (num >= 10)
		{
			c = num % 10 + '0';
			ft_putnbr_pf(num / 10, counter);
			ft_putchar_pf(c, counter);
		}
		else
		{
			c = num % 10 + '0';
			ft_putchar_pf(c, counter);
		}
	}
}
