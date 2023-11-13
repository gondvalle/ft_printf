/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:06:58 by gdel-val          #+#    #+#             */
/*   Updated: 2023/11/13 17:07:56 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	longnum(unsigned int num)
{
	int	i;

	i = 0;
	if (num == 0)
		i = 1;
	while (num)
	{
		num = num / 16;
		i++;
	}
	return (i);
}

void	ft_puthex_pf(unsigned int num, size_t *counter)
{
	int				i;
	const char		*hexa;
	char			*src;

	hexa = "0123456789abcdef";
	i = longnum(num);
	src = malloc(i + 1);
	if (!src)
		return ;
	src[i] = '\0';
	if (num == 0)
		src[0] = '0';
	while (num)
	{
		i--;
		src[i] = hexa[num % 16];
		num = num / 16;
	}
	ft_putstr_pf(src, counter);
	free(src);
}
