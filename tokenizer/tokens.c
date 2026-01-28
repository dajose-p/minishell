/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:36:52 by danjose-          #+#    #+#             */
/*   Updated: 2026/01/28 21:11:23 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

char	check_sp_char(char first_split);

t_tokens    *main_tokenize(char *input)
{
	char	**first_split;
	char	sp_char
	int	i;
	t_tokens	*str_tokens;

	str_tokens = NULL;
	i = 0;
	first_split = ft_split_v2(input);
	while (first_split[i])
	{
		j = 0;
		while (first_split[i][j])
		{
			sp_char = check_sp_char(first_split[i][j]);
		}
	}
}