/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 16:59:07 by fernfern          #+#    #+#             */
/*   Updated: 2026/09/29 19:59:56 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H



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

#endif