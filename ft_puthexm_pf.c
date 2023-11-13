/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexM_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:33:01 by gdel-val          #+#    #+#             */
/*   Updated: 2023/11/13 17:17:08 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	longnumx(unsigned int num)
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

void	ft_puthexm_pf(unsigned int num, size_t *counter)
{
	int				i;
	const char		*hexa;
	char			*src;

	hexa = "0123456789ABCDEF";
	i = longnumx(num);
	src = malloc(i + 1);
	if (!src)
		return ;
	src[i] = '\0';
	if (num == 0)
		src[0] = '0';
	while (num > 0)
	{
		i--;
		src[i] = hexa[num % 16];
		num = num / 16;
	}
	ft_putstr_pf(src, counter);
	free(src);
}
