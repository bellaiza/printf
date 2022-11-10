/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporfiri <iporfiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 00:42:23 by iporfiri          #+#    #+#             */
/*   Updated: 2022/11/10 20:22:59 by iporfiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex_up(unsigned int hex, int len)
{
	if (hex >= 16)
		len += ft_printhex_up(hex / 16, len);
	len += write(1, &HEX_UP[hex % 16], 1);
	return (len);
}

int	ft_printhex_lw(unsigned int hex, int len)
{
	if (hex >= 16)
		len += ft_printhex_lw(hex / 16, len);
	len += write(1, &HEX_LW[hex % 16], 1);
	return (len);
}

int	ft_printhex_add(unsigned long long hex, int len)
{
	if (hex >= 16)
		len += ft_printhex_add(hex / 16, len);
	len += write(1, &HEX_LW[hex % 16], 1);
	return (len);
}

int	ft_printptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (!ptr)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	len += write(1, "0x", 2);
	len += ft_printhex_add(ptr, 0);
	return (len);
}

int	ft_putunbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count = count + ft_putchar('-');
		count = count + ft_putnbr(n * -1);
	}
	else if (n > 9)
	{
		count = count + ft_putnbr(n / 10);
		count = count + ft_putnbr(n % 10);
	}
	else
		count = count + ft_putchar(n + '0');
	return (count);
}
