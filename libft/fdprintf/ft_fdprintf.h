/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:37:36 by marc              #+#    #+#             */
/*   Updated: 2024/08/22 22:16:36 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDPRINTF_H
# define FT_FDPRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>

int			ft_fdprintf(int fd, const char *format, ...);
int			fd_pf_isflag(char c);
int			fd_pf_inthub(int fd, long long n, char c, int len);
int			fd_pf_phub(int fd, unsigned long long n);
int			fd_pf_flag_distribution(int fd, char c, va_list arg);
int			fd_pf_putstr(int fd, const char *s);
int			fd_pf_putchar(int fd, char c);
void		fd_pf_putnbr(int fd, int n);
void		fd_pf_putunsigned(int fd, unsigned long long n,
				unsigned long long len, char *base);
void		fd_pf_putnbr_base(int fd, long long n, char *base);

#endif