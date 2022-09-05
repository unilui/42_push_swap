/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:32:01 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/03 00:13:46 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *str, char sep);
static char	*new_word(char const *str, char sep);

char	**ft_split(char const *str, char sep)
{
	char	**split_str;
	int		words;
	int		i;

	i = 0;
	words = word_count(str, sep);
	split_str = malloc((words + 1) * sizeof(char *));
	if (!split_str)
		return (NULL);
	while (i < words)
		split_str[i++] = new_word(str, sep);
	split_str[i] = NULL;
	return (split_str);
}

static int	word_count(char const *str, char sep)
{
	int	words;

	words = 1;
	while (*str == sep)
		str++;
	while (*str)
	{
		if (*str == sep && (*(str + 1) != sep) && *(str + 1))
			words++;
		str++;
	}
	return (words);
}

static char	*new_word(char const *str, char sep)
{
	static int	offset;
	int			letters;
	int			reverse;
	char		*word;

	letters = 0;
	reverse = 1;
	while (str[offset] == sep)
		offset++;
	while (str[offset] != sep && str[offset])
	{
		letters++;
		offset++;
	}
	word = malloc(letters + 1);
	if (!word)
		return (NULL);
	word[letters--] = '\0';
	while (letters >= 0)
		word[letters--] = str[offset - reverse++];
	if (!str[offset])
		offset = 0;
	return (word);
}
