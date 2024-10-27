/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:17:19 by malia             #+#    #+#             */
/*   Updated: 2024/01/23 09:27:05 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
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
		if (format[i] == '%' && pf_isflag(format[i + 1]))
		{
			i++;
			len += pf_flag_distribution(format[i], arg);
		}
		else
			len += pf_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (len);
}

int	pf_isflag(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int	pf_inthub(long long n, char c, int len)
{
	int	count;

	count = 1;
	if (n == -2147483648)
		return (pf_putstr("-2147483648"));
	if (c == 'u')
		pf_putunsigned(n, len, "0123456789");
	else if (c == 'd' || c == 'i')
		pf_putnbr(n);
	else if (c == 'x')
		pf_putnbr_base(n, "0123456789abcdef");
	else if (c == 'X')
		pf_putnbr_base(n, "0123456789ABCDEF");
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

int	pf_phub(unsigned long long n)
{
	int	count;

	count = 1;
	if (n == 0)
		return (pf_putstr("(nil)"));
	count += pf_putstr("0x");
	pf_putunsigned(n, 16, "0123456789abcdef");
	while (n > 15)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

int	pf_flag_distribution(char c, va_list arg)
{
	if (c == 'c')
		return (pf_putchar(va_arg(arg, int)));
	else if (c == 's')
		return (pf_putstr(va_arg(arg, const char *)));
	else if (c == 'd' || c == 'i')
		return (pf_inthub(va_arg(arg, int), c, 10));
	else if (c == 'u')
		return (pf_inthub(va_arg(arg, unsigned int), c, 10));
	else if (c == 'x' || c == 'X')
		return (pf_inthub(va_arg(arg, unsigned int), c, 16));
	else if (c == 'p')
		return (pf_phub(va_arg(arg, unsigned long long)));
	else
		return (pf_putchar('%'));
}
