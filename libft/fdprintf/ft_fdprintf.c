/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:41:50 by marc              #+#    #+#             */
/*   Updated: 2024/08/22 20:47:18 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdprintf.h"

int	ft_fdprintf(int fd, const char *format, ...)
{
	int		i;
	int		len;
	va_list	arg;

	i = 0;
	len = 0;
	if (!format)
		return (-1);
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%' && fd_pf_isflag(format[i + 1]))
		{
			i++;
			len += fd_pf_flag_distribution(fd, format[i], arg);
		}
		else
			len += fd_pf_putchar(fd, format[i]);
		i++;
	}
	va_end(arg);
	return (len);
}

int	fd_pf_isflag(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int	fd_pf_inthub(int fd, long long n, char c, int len)
{
	int	count;

	count = 1;
	if (n == -2147483648)
		return (fd_pf_putstr(fd, "-2147483648"));
	if (c == 'u')
		fd_pf_putunsigned(fd, n, len, "0123456789");
	else if (c == 'd' || c == 'i')
		fd_pf_putnbr(fd, n);
	else if (c == 'x')
		fd_pf_putnbr_base(fd, n, "0123456789abcdef");
	else if (c == 'X')
		fd_pf_putnbr_base(fd, n, "0123456789ABCDEF");
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > len - 1)
	{
		n = n / len;
		count++;
	}
	return (count);
}

int	fd_pf_phub(int fd, unsigned long long n)
{
	int	count;

	count = 1;
	if (n == 0)
		return (fd_pf_putstr(fd, "(nil)"));
	count += fd_pf_putstr(fd, "0x");
	fd_pf_putunsigned(fd, n, 16, "0123456789abcdef");
	while (n > 15)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

int	fd_pf_flag_distribution(int fd, char c, va_list arg)
{
	if (c == 'c')
		return (fd_pf_putchar(fd, va_arg(arg, int)));
	else if (c == 's')
		return (fd_pf_putstr(fd, va_arg(arg, const char *)));
	else if (c == 'd' || c == 'i')
		return (fd_pf_inthub(fd, va_arg(arg, int), c, 10));
	else if (c == 'u')
		return (fd_pf_inthub(fd, va_arg(arg, unsigned int), c, 10));
	else if (c == 'x' || c == 'X')
		return (fd_pf_inthub(fd, va_arg(arg, unsigned int), c, 16));
	else if (c == 'p')
		return (fd_pf_phub(fd, va_arg(arg, unsigned long long)));
	else
		return (fd_pf_putchar(fd, '%'));
}
