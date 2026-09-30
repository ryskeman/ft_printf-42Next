/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 16:59:07 by fernfern          #+#    #+#             */
/*   Updated: 2026/09/30 19:38:11 by fernfern         ###   ########.fr       */
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
	int		minus;		// Flag '-' (alineación izquierda)
	int		zero;		// Flag '0' (relleno con ceros)
	int		dot;		// Presencia de precisión '.' (1 si existe, 0 si no)
	int		precision;	// Valor numérico de la precisión
	int		width;		// Ancho mínimo de campo
	int		hash;		// Flag '#' (prefijo 0x o 0X)
	int		plus;		// Flag '+' (fuerza signo + en positivos)
	int		space;		// Flag ' ' (espacio si no hay signo)
	char	specifier;	// cspdiuxX%
}		t_flags;

/* I/O UTILS */
int		ft_putchar_ret(char c, int fd);
int		print_padding(char c, int len);

/* PARSER & DISPATCHER */
void	parser(char **fmt, t_flags *flags);
int		format_conversor(char conv, va_list args, t_flags *flags);
int		print_arg(va_list args, char **fmt);

/* CONVERSIONS (stubs provisionales para compilar) */
int		print_char(int c, t_flags *flags);
int		print_str(const char *s, t_flags *flags);
int		print_ptr(void *p, t_flags *flags);
int		print_int(int n, t_flags *flags);
int		print_uint(unsigned int n, t_flags *flags);
int		print_hex(unsigned int n, int uppercase, t_flags *flags);

/* MAIN FUNCTION */
int		ft_printf(char const *format, ...);

#endif