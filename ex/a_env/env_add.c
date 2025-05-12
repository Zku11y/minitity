/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 23:16:17 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/12 08:24:43 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

int	env_add(char *name, char *valve, t_env **head)
{
	t_env	*tmp;
	t_env	*neo;

	neo = ft_calloc(sizeof(t_env), 1);
	if (!neo)
		return (1);
	neo->name = name;
	neo->valve = valve;
	neo->next = NULL;
	if (head == NULL)
	 	head = &neo;
	else
	{
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = neo;
	}
	return (0);
}
