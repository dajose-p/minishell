/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:33:33 by danjose-          #+#    #+#             */
/*   Updated: 2026/01/13 20:12:08 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	is_builtin(char *input)
{
	if (ft_strncmp(input, "echo", ft_strlen("echo")) == 0)
		return (1);
	if (ft_strncmp(input, "cd", ft_strlen("cd")) == 0)
                return (1);
	if (ft_strncmp(input, "pwd", ft_strlen("exit")) == 0)
                return (1);
	if (ft_strncmp(input, "export", ft_strlen(input)) == 0)
                return (1);
	if (ft_strncmp(input, "unset", ft_strlen(input)) == 0)
                return (1);
	if (ft_strncmp(input, "env", ft_strlen(input)) == 0)
                return (1);
	if (ft_strncmp(input, "exit", ft_strlen("exit")) == 0)
                return (1);
	return (0);
}

static void     do_builtin(char *input)
{
        char	*path;

	if (ft_strncmp(input, "echo", ft_strlen("echo")) == 0)
		echo_builtin(input);
	if (ft_strncmp(input, "cd", ft_strlen("cd")) == 0)
                cd_builtin(input);
	if (ft_strncmp(input, "pwd", ft_strlen("pwd")) == 0)
	{
		path = pwd_builtin();
		printf("%s\n", path);
	}
        /*if (ft_strncmp(input, "export", ft_strlen(input)))
                export_builtin(input);
        if (ft_strncmp(input, "unset", ft_strlen(input)))
                unset_builtin(input);
        if (ft_strncmp(input, "env", ft_strlen(input)))
                env_builtin(input);*/
	if (ft_strncmp(input, "exit", ft_strlen("exit")) == 0)
                exit_builtin();
}

void	parser_checker(char *input)
{
	if (is_builtin(input))
		do_builtin(input);
	else
		return; //TODO add parser
}
