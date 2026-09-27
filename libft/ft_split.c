/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 02:27:41 by fernfern          #+#    #+#             */
/*   Updated: 2026/09/25 02:27:46 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static void	*ft_free_split(char **matrix, int idx)
{
	while (idx > 0)
	{
		idx--;
		free(matrix[idx]);
	}
	free(matrix);
	return (NULL);
}

static char	**ft_fill(char const *s, char c, char **matrix)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				len = ft_strlen(s);
			else
				len = ft_strchr(s, c) - s;
			matrix[i] = ft_substr(s, 0, len);
			if (!matrix[i])
				return (ft_free_split(matrix, i));
			i++;
			s += len;
		}
	}
	matrix[i] = NULL;
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	matrix = malloc(sizeof(char *) * (words + 1));
	if (!matrix)
		return (NULL);
	return (ft_fill(s, c, matrix));
}
