/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 14:00:22 by fernfern          #+#    #+#             */
/*   Updated: 2026/10/01 14:08:40 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parser(char **fmt, t_flags *flags)
{
	ft_bzero(flags, sizeof(t_flags));
	flags->specifier = **fmt;
}
