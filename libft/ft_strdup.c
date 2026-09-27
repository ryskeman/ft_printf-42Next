/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 15:10:36 by fernfern          #+#    #+#             */
/*   Updated: 2026/09/24 15:11:23 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_copy;
	size_t	s_size;

	s_size = ft_strlen(s);
	s_copy = malloc(s_size + 1);
	if (s_copy == NULL)
		return (NULL);
	ft_memcpy(s_copy, s, s_size + 1);
	return (s_copy);
}
