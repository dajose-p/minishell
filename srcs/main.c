/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:53:37 by danjose-          #+#    #+#             */
/*   Updated: 2026/01/24 21:27:05 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// void	print_env(char **envp)
// {
// 	int	i = 0;

// 	while (envp[i])
// 	{
// 		printf("%s\n", envp[i]);
// 		i++;
// 	}
// }

// void	print_cp_env(t_env *env)
// {
// 	t_env	*head;

// 	head = env;
// 	while (head)
// 	{
// 		printf("%s=%s\n", head->key, head->value);
// 		head = head->next;
// 	}
// }

void	free_split(char **to_free)
{
	int	i;

	i = 0;
	while (to_free[i])
	{
		free(to_free[i]);
		i++;
	}
}

void	set_env(t_env **env, char **envt)
{
	char	**sp_env;
	int	i;

	i = 0;
	while (envt[i])
	{
		sp_env = ft_split(envt[i], '=');
		insert_el(env, sp_env[0], sp_env[1]);
		i++;
	}
}

int main(int argc, char **argv, char **envp)
{
	char	*input;
	char	*curr_path;
	t_env	*env;

	(void)argc;
	(void)argv;
	set_env(&env, envp);
	while (1)
	{
		curr_path = pwd_builtin();
		printf(MAGENTA "%s", getenv("USER"));
		printf("@minishell: ");
		printf(BLUE "%s", curr_path);
		input = readline("$ " RESET);
		parser_checker(input);
		rl_on_new_line();
	}
	free(input);
	return (0);
}
