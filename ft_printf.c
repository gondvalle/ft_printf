/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:54:06 by gdel-val          #+#    #+#             */
/*   Updated: 2023/11/13 17:48:12 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list va, char *str, size_t *counter)
{
	if (*str == 'c')
		ft_putchar_pf(va_arg(va, int), counter);
	else if (*str == 's')
		ft_putstr_pf(va_arg(va, char *), counter);
	else if (*str == 'p')
		ft_putptr_pf(va_arg(va, void *), counter);
	else if (*str == 'i' || *str == 'd')
		ft_putnbr_pf(va_arg(va, int), counter);
	else if (*str == 'u')
		ft_putuint_pf(va_arg(va, unsigned int), counter);
	else if (*str == 'x')
		ft_puthex_pf(va_arg(va, unsigned int), counter);
	else if (*str == 'X')
		ft_puthexm_pf(va_arg(va, unsigned int), counter);
	else if (*str == '%')
		ft_putchar_pf(*str, counter);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	size_t	counter;

	if (!str)
		return (0);
	counter = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str != '%')
			ft_putchar_pf(*str, &counter);
		else
		{
			str++;
			ft_format(args, (char *)str, &counter);
		}
		str++;
	}
	va_end(args);
	return ((int) counter);
}
/*
int main()
{
	char *str;
	unsigned int	num;

	str = "hola";
	num = 0;
	int sec = ft_printf("%x", 32);
	ft_printf("\n%i", sec);
	int nump = printf("\nprintf %x", 32);
	printf("\n%i\n", nump);
	return 0;
}*/
