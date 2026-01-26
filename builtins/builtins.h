/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 20:00:12 by danjose-          #+#    #+#             */
/*   Updated: 2026/01/26 20:13:48 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../minishell.h"

void	echo_builtin(char *input);
char	*pwd_builtin(void);
void	exit_builtin(void);
void	cd_builtin(char *input);
void	do_builtin(char *input);

#endif