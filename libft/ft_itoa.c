/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:52:51 by malia             #+#    #+#             */
/*   Updated: 2023/11/10 17:06:51 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lenint(long long n)
{
	int	count;

	count = 1;
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static int	alloc(char *str, int flag, int len, long long num)
{
	if (num == 0)
		str[0] = '0';
	if (flag)
	{
		str[0] = '-';
		len++;
	}
	str[len] = '\0';
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			flag;
	int			len;
	long long	num;

	num = n;
	flag = 0;
	if (num < 0)
	{
		num *= -1;
		flag = 1;
	}
	len = lenint(num);
	str = (char *)malloc(sizeof(char) * (len + 1 + flag));
	if (!str)
		return (NULL);
	len = alloc(str, flag, len, num);
	while (num > 0)
	{
		str[len - 1] = num % 10 + '0';
		num /= 10;
		len--;
	}
	return (str);
}
