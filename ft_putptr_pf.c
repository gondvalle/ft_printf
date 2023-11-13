/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:14:33 by gdel-val          #+#    #+#             */
/*   Updated: 2023/11/13 17:49:59 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	longnum3(unsigned long int num)
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

char	*puthex(unsigned long int num)
{
	int				i;
	const char		*hexa;
	char			*src;

	hexa = "0123456789abcdef";
	i = longnum3(num);
	src = malloc(i + 1);
	if (!src)
		return (NULL);
	src[i] = '\0';
	if (num == 0)
		src[0] = '0';
	while (num)
	{
		i--;
		src[i] = hexa[num % 16];
		num = num / 16;
	}
	return (src);
}

void	ft_putptr_pf(void *ptr, size_t *counter)
{
	unsigned long int	num;
	char				*src;

	num = (unsigned long int)ptr;
	ft_putstr_pf("0x", counter);
	src = puthex(num);
	if (!src)
		return ;
	ft_putstr_pf(src, counter);
	free(src);
}
