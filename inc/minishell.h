/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:54:11 by danjose-          #+#    #+#             */
/*   Updated: 2025/12/22 19:25:00 by danjose-         ###   ########.fr       */
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


void	parser_checker(char *input);
void	echo_builtin(char *input);
void	pwd_builtin(void);

#endif
