/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 23:13:09 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/06 00:00:41 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

t_env	*env_init(t_data *data, char **old_env)
{
	int		i;
	int		j;
	t_env	*neo;

	i = 0;
	j = 0;
	neo = NULL;
	while (old_env[i])
	{
		while (old_env)
		{
			env_add();
			i++;
		}
		i++;
	}
	return (neo);
}

