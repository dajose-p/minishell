/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 20:04:22 by danjose-          #+#    #+#             */
/*   Updated: 2026/01/26 20:11:36 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	do_builtin(char *input)
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