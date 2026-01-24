/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:31:42 by danjose-          #+#    #+#             */
/*   Updated: 2026/01/22 23:29:41 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void    lstadd_front(t_env **env)
{
        t_env *new;

        new = malloc(sizeof(t_env));
        if (!new)
                return ;
        new->key = (*env)->key;
        new->value = (*env)->value;
        new->next = *env;
        *env = new;
}

void    insert_el(t_env **env, char *key, char *value)
{
        t_env *new;
        t_env   *head;

        head = *env;
        new = malloc(sizeof(t_env));
        if (!new)
                return ;
        new->key = key;
        new->value = value;
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
