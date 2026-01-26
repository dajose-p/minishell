/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:54:11 by danjose-          #+#    #+#             */
/*   Updated: 2026/01/26 20:14:01 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "builtins/builtins.h"

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RED "\033[0;31m"
# define CYAN "\033[0;36m"
# define BLUE "\033[0;34m"
# define MAGENTA "\x1B[35m"
# define RESET "\033[0m"

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

void	parser_checker(char *input);
void	insert_el(t_env **env, char *key, char *value);
void	set_env(t_env **env, char **envt);
void	free_list(t_env **env);

#endif
