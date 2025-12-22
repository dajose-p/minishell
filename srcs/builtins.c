/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 23:34:00 by danjose-          #+#    #+#             */
/*   Updated: 2025/12/22 19:34:52 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	echo_builtin(char *input)
{
	char	**split;
	int	i;
	
	i = 1;
	split = ft_split(input, ' ');
	while (split[i])
	{
		printf("%s", split[i]);
		if (split[i + 1] != NULL)
			printf(" ");
		i++;
	}
	printf("\n");
}

void	pwd_builtin(void)
{
	char	*dir;

	dir = getcwd(NULL, 0);
	printf("%s\n", dir);
}
