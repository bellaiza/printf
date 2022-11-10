/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporfiri <iporfiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 00:42:05 by iporfiri          #+#    #+#             */
/*   Updated: 2022/11/10 20:21:25 by iporfiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# define HEX_LW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_printhex_up(unsigned int hex, int len);
int	ft_printhex_lw(unsigned int hex, int len);
int	ft_printhex_add(unsigned long long hex, int len);
int	ft_printptr(unsigned long long ptr);
int	ft_putunbr(unsigned int n);
int	treatment(const char *format, int i, char c, va_list ptr);
int	ft_printf(const char *format, ...);

#endif