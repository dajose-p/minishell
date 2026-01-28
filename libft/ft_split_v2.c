/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_v2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:54:04 by danjose-          #+#    #+#             */
/*   Updated: 2026/01/28 21:06:52 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if ((!(s[i] >= ' ' && s[i] <= '\v')) && (i == 0 || (s[i - 1] >= ' ' && s[i - 1] <= '\v')))
			words++;
		i++;
	}
	return (words);
}

static int	word_length(char const *s, int i)
{
	int	len;

	len = 0;
	while (s[i] != '\0' && (!(s[i] >= ' ' && s[i] <= '\v')))
	{
		len++;
		i++;
	}
	return (len);
}

static void	free_mem(char **arr, int i)
{
	while (i-- > 0)
		free(arr[i]);
	free(arr);
}

static char	**allocate_memory(char const *s, int word_count)
{
	char	**arr;
	int		i;
	int		j;

	arr = malloc((word_count + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < word_count)
	{
		while (s[j] >= ' ' && s[j] <= '\v')
			j++;
		arr[i] = malloc((word_length(s, j) + 1) * sizeof(char));
		if (arr[i] == NULL)
		{
			free_mem(arr, i);
			return (NULL);
		}
		j += word_length(s, j);
		i++;
	}
	arr[i] = NULL;
	return (arr);
} 

char	**ft_split_v2(char const *s)
{
	char	**arr;
	int		word_count;
	int		i;
	int		j;
	int		k;

	if (s == NULL)
		return (NULL);
	word_count = count_words(s);
	arr = allocate_memory(s, word_count);
	if (arr == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (i < word_count)
	{
		while (s[k] >= ' ' && s[k] <= '\v')
			k++;
		j = 0;
		while ((!(s[k] >= ' ' && s[k] <= '\v')) && s[k] != '\0')
			arr[i][j++] = s[k++];
		arr[i][j] = '\0';
		i++;
	}
	return (arr);
}