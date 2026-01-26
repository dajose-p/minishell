/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:59:02 by danjose-          #+#    #+#             */
/*   Updated: 2026/01/26 19:59:50 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

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