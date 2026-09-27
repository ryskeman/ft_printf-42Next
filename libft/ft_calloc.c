/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 15:10:22 by fernfern          #+#    #+#             */
/*   Updated: 2026/09/24 15:10:28 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*generic_array;

	total_size = 0;
	if (nmemb == 0 || size == 0)
		total_size = 0;
	else if (nmemb > SIZE_MAX / size)
		return (NULL);
	else
		total_size = nmemb * size;
	generic_array = malloc(total_size);
	if (generic_array == 0)
		return (NULL);
	ft_memset(generic_array, 0, total_size);
	return (generic_array);
}
