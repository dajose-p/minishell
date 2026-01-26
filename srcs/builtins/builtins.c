/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 23:34:00 by danjose-          #+#    #+#             */
/*   Updated: 2026/01/13 20:11:04 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	echo_builtin(char *input)
{
	char	**split;
	size_t	i;

	split = ft_split(input, ' ');
	i = 1;
	while (split[i])
	{
		printf("%s", split[i]);
		if (split[i + 1] != NULL)
			printf(" ");
		i++;
	}
	printf("\n");
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

char	*pwd_builtin(void)
{
	char	*dir;

	dir = getcwd(NULL, 0);
	return (dir);
}

void	exit_builtin(void)
{
	exit(0);
}

void	cd_builtin(char *input)
{
	char	**split;
	int	i;
	
	i = 1;
	split = ft_split(input, ' ');
	while (split[i])
		i++;
	if (i > 2)
	{
		printf("cd error");
		return ;
	}
	chdir(split[1]);
}
