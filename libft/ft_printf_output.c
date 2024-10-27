/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:32:37 by malia             #+#    #+#             */
/*   Updated: 2024/08/23 13:09:38 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_putstr(const char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	pf_putchar(char c)
{
	return (write(1, &c, 1));
}

void	pf_putnbr(int n)
{
	if (n >= -2147483647 && n <= 2147483647)
	{
		if (n >= 0 && n < 10)
			pf_putchar(n + 48);
		else if (n < 0)
		{
			pf_putchar('-');
			pf_putnbr(n * (-1));
		}
		else
		{
			pf_putnbr(n / 10);
			pf_putnbr(n % 10);
		}
	}
}

void	pf_putunsigned(unsigned long long n, unsigned long long len, char *base)
{
	if (n == 0)
		write(1, &base[n], 1);
	else if (n > 0 && n < len)
		write(1, &base[n], 1);
	else
	{
		pf_putunsigned(n / len, len, base);
		pf_putunsigned(n % len, len, base);
	}
}

void	pf_putnbr_base(long long n, char *base)
{
	if (n < 0)
	{
		write(1, "-", 1);
		pf_putnbr_base((n / 16) * (-1), base);
		write(1, &base[n % 16], 1);
	}
	else if (n >= 0 && n < 16)
		write(1, &base[n], 1);
	else
	{
		pf_putnbr_base(n / 16, base);
		pf_putnbr_base(n % 16, base);
	}
}
