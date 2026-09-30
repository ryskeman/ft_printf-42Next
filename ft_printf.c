/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 15:29:45 by fernfern          #+#    #+#             */
/*   Updated: 2026/09/30 19:34:51 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	int		printed;
	va_list	args;

	if (!format)
		return (-1);
	if (*format == '%' && *(format + 1) == '\0')
		return (-1);
	printed = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			printed += print_arg(args, (char **)&format);
		}
		else
			printed += ft_putchar_ret(*format, 1);
		format++;
	}
	if (printed == -1)
		return (va_end(args), -1);
	va_end(args);
	return (printed);
}
