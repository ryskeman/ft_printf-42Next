/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 16:59:07 by fernfern          #+#    #+#             */
/*   Updated: 2026/10/02 02:56:05 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		dot;
	int		precision;
	int		width;
	int		hash;
	int		plus;
	int		space;
	char	specifier;
}		t_flags;

/* I/O UTILS */
int		ft_putchar_ret(char c, int fd);
int		print_padding(char c, int len);

/* HEX UTILS */
int		get_hex_len(unsigned long n);
void	put_hex_rec(unsigned long n, const char *base);

/* PARSER & DISPATCHER */
void	parser(char **fmt, t_flags *flags);
int		format_conversor(char conv, va_list args, t_flags *flags);
int		print_arg(va_list args, char **fmt);

/* CONVERSIONS */
int		print_char(int c, t_flags *flags);
int		print_str(const char *s, t_flags *flags);
int		print_ptr(void *p, t_flags *flags);
int		print_int(long n, t_flags *flags);
int		print_hex(unsigned int n, int uppercase, t_flags *flags);

/* MAIN FUNCTION */
int		ft_printf(char const *format, ...);

#endif