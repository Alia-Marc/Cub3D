/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdprintf_output.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:36:42 by marc              #+#    #+#             */
/*   Updated: 2024/08/23 13:09:26 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdprintf.h"
#include "../libft.h"

int	fd_pf_putstr(int fd, const char *s)
{
	if (!s)
		return (write(fd, "(null)", 6));
	return (write(fd, s, ft_strlen(s)));
}

int	fd_pf_putchar(int fd, char c)
{
	return (write(fd, &c, 1));
}

void	fd_pf_putnbr(int fd, int n)
{
	if (n >= -2147483647 && n <= 2147483647)
	{
		if (n >= 0 && n < 10)
			fd_pf_putchar(fd, n + 48);
		else if (n < 0)
		{
			fd_pf_putchar(fd, '-');
			fd_pf_putnbr(fd, n * (-1));
		}
		else
		{
			fd_pf_putnbr(fd, n / 10);
			fd_pf_putnbr(fd, n % 10);
		}
	}
}

void	fd_pf_putunsigned(int fd, unsigned long long n,
							unsigned long long len, char *base)
{
	if (n == 0)
		write(fd, &base[n], 1);
	else if (n > 0 && n < len)
		write(fd, &base[n], 1);
	else
	{
		fd_pf_putunsigned(fd, n / len, len, base);
		fd_pf_putunsigned(fd, n % len, len, base);
	}
}

void	fd_pf_putnbr_base(int fd, long long n, char *base)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		fd_pf_putnbr_base(fd, (n / 16) * (-1), base);
		write(fd, &base[n % 16], 1);
	}
	else if (n >= 0 && n < 16)
		write(fd, &base[n], 1);
	else
	{
		fd_pf_putnbr_base(fd, n / 16, base);
		fd_pf_putnbr_base(fd, n % 16, base);
	}
}
