/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:53:37 by danjose-          #+#    #+#             */
/*   Updated: 2025/12/22 19:12:51 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int main(void)
{
	char	*login;
	char	*input;

	login = getenv("USER");
	while (1)
	{
		printf(MAGENTA "%s",login);
		input = readline("@minishell$>" RESET);
		parser_checker(input);
		rl_on_new_line();
	}
	free(input);
	return (0);
}
