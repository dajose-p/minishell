/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:53:37 by danjose-          #+#    #+#             */
/*   Updated: 2025/12/15 23:28:25 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int main(void)
{
	char	*login;

	login = getenv("USER");
	while (1)
	{
		printf("%s@minishell$>", login);
		readline(NULL);
	}
	return (0);
}
