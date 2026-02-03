/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:31:42 by danjose-          #+#    #+#             */
/*   Updated: 2026/02/03 21:30:26 by danjose-         ###   ########.fr       */
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

	while (*env)
	{
		head = *env;
		*env = (*env)->next;
		free(head);
	}
}
