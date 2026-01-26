/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:31:42 by danjose-          #+#    #+#             */
/*   Updated: 2026/01/26 20:06:18 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	insert_el(t_env **env, char *key, char *value)
{
	t_env	*new;
	t_env	*head;

	head = *env;
	new = malloc(sizeof(t_env));
	if (!new)
		return ;
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->next = NULL;
	if (*env == NULL)
	{
		*env = new;
		return ;
	}
	while (head->next)
		head = head->next;
	head->next = new;
}

void	free_list(t_env **env)
{
	t_env	*head;

	head = *env;
	while (head)
	{
		free(head->key);
		free(head->value);
		free(head);
		head = head->next;
	}
}
