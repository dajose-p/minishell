/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 23:34:00 by danjose-          #+#    #+#             */
/*   Updated: 2025/12/16 00:35:34 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	echo_builtin(char **args)
{
	int	i;

	i = 0;

	while (args[i])
	{
		ft_putstr(args[i]);
		i++;
	}
}

void	pwd_builtin(void)
{
	char	*dir;
	size_t	size;

	getcwd(dir, size);
	printf("%s", dir);
}
