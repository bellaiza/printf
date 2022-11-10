/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporfiri <iporfiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 00:42:14 by iporfiri          #+#    #+#             */
/*   Updated: 2022/11/10 23:32:32 by iporfiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count = count + ft_putchar('-');
		count = count + ft_putchar('2');
		count = count + ft_putnbr(147483648);
	}
	else if (n < 0)
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

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i] != '\0')
	{
		count = count + ft_putchar(s[i]);
		i++;
	}
	return (count);
}

int	treatment(const char *format, int i, char c, va_list ptr)
{
	int	len;

	len = 0;
	if (format[i] == 'i' || format[i] == 'd')
		len = len + ft_putnbr(va_arg(ptr, int));
	else if (format[i] == 's')
		len = len + ft_putstr(va_arg(ptr, char *));
	else if (format[i] == 'c')
		len = len + ft_putchar(va_arg(ptr, int));
	else if (format[i] == 'p')
		len = len + ft_printptr(va_arg(ptr, long long));
	else if (format[i] == 'u')
		len = len + ft_putunbr(va_arg(ptr, unsigned int));
	else if (format[i] == 'x')
		len = len + ft_printhex_lw(va_arg(ptr, int), 0);
	else if (format[i] == 'X')
		len = len + ft_printhex_up(va_arg(ptr, int), 0);
	else if (format[i] == '%')
		len = len + ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ptr;
	int		len;

	va_start(ptr, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += treatment(format, i, format[i], ptr);
		}
		else
			len = len + ft_putchar(format[i]);
		i++;
	}
	return (len);
}
