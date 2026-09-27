/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:37:57 by fernfern          #+#    #+#             */
/*   Updated: 2026/09/23 16:38:01 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return ((char *)&s[s_len]);
	while (s_len--)
	{
		if (s[s_len] == (unsigned char)c)
			return ((char *)&s[s_len]);
	}
	return (0);
}
