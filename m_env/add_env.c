/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:50:36 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/17 21:51:26 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ex.h"

int	add_env(t_env *env, char *key, char *value)
{
	int	l;

	t_env (*nu_env), (*tm_env);
	if (key == NULL || env == NULL)
		return (1);
	tm_env = env;
	l = ft_strlen(key);
	while (tm_env != NULL)
	{
		if (tm_env->key[l] == '\0' && ft_strncmp(tm_env->key, key, l) == 0)
		{
			free(tm_env->value);
			tm_env->value = ft_strdup(value);
			return (0);
		}
		if (tm_env->next == NULL)
			break;
		tm_env = tm_env->next;
	}
	nu_env = ft_calloc(sizeof(t_env), 1);
	nu_env->key = ft_strdup(key);
	nu_env->value = ft_strdup(value);
	nu_env->next = NULL;
	tm_env->next = nu_env;
	return (0);
}
