/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 18:03:16 by fernfern          #+#    #+#             */
/*   Updated: 2026/09/30 19:41:46 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Putchar with return value */
int	ft_putchar_ret(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	print_padding(char c, int len);

int	print_char(int c, t_flags *flags);

int	print_str(const char *s, t_flags *flags);