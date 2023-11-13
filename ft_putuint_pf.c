/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:14:29 by gdel-val          #+#    #+#             */
/*   Updated: 2023/11/03 20:17:32 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuint_pf(unsigned int num, size_t *counter)
{
	char	c;

	if (num >= 10)
	{
		c = num % 10 + '0';
		ft_putuint_pf(num / 10, counter);
		(*counter) += write(1, &c, 1);
	}
	else
	{
		c = num % 10 + '0';
		(*counter) += write(1, &c, 1);
	}
}
