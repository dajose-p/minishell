/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:57:54 by danjose-          #+#    #+#             */
/*   Updated: 2026/01/26 20:07:24 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	cd_builtin(char *input)
{
	char	**split;
	int		i;

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