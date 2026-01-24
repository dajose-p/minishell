/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:54:11 by danjose-          #+#    #+#             */
/*   Updated: 2026/01/13 20:10:03 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RED "\033[0;31m"
# define CYAN "\033[0;36m"
# define BLUE "\033[0;34m"
# define MAGENTA "\x1B[35m"
#define RESET "\033[0m"

typedef struct s_env
{
	char *key;
	char *value;
	struct s_env *next;
}	t_env;

void	parser_checker(char *input);
void	echo_builtin(char *input);
char	*pwd_builtin(void);
void	exit_builtin(void);
void	cd_builtin(char *input);
void    insert_el(t_env **env, char *key, char *value);
void	set_env(t_env **env, char **envt);

#endif
