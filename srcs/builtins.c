/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 23:34:00 by danjose-          #+#    #+#             */
/*   Updated: 2026/01/07 19:26:13 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	echo_builtin(char *input)
{
	char	**split;
	size_t	i;
	size_t	j;
	
	i = 1;
	split = ft_split(input, ' ');
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{	
			if (split[i][j] == '"' && ((i == 1 && j == 0) 
					|| (i == ft_strlen(input) && j == i)))
				j++;
			ft_putchar_fd(split[i][j], 1);
			j++;
		}
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

void	pwd_builtin(void)
{
	char	*dir;

	dir = getcwd(NULL, 0);
	printf("%s\n", dir);
}

void	exit_builtin(void)
{
	exit(0);
}
