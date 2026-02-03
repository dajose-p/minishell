/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:38:15 by danjose-          #+#    #+#             */
/*   Updated: 2026/01/28 19:46:07 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

#include "../minishell.h"

typedef enum	e_tokens
{
	WORD
}	t_en_tokens;

typedef struct	s_tokens
{
	t_en_tokens token_type;
	char	*value;
	struct s_tokens *next;
}	t_tokens;

t_tokens    *main_tokenize(char *input);

#endif
