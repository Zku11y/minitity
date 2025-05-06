/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 23:16:17 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/06 00:17:24 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

int	env_add(char *name, char **valve, t_data *data)
{
	t_env	*tmp;
	t_env	*neo;

	tmp = data->env;
	while (tmp->next)
		tmp = (data->env)->next;
	neo = ft_calloc(sizeof(t_env), 1);
	if (!neo)
		return (1);
	neo->name = name;
	neo->valve = valve;
	neo->next = NULL;
	tmp->next = neo;
	return (0);
}
