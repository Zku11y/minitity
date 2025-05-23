/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:50:36 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/23 08:44:13 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_env	*add_env(t_env *env, char *key, char *value, bool ported)
{
	int	l;

	t_env (*nu_env), (*tm_env);
	if (key == NULL)
		return (NULL);
	tm_env = env;
	l = ft_strlen(key);
	tm_env = grp_env(env, key);
	if (!tm_env)
	{
		nu_env = ft_calloc(sizeof(t_env), 1);
		nu_env->key = ft_strdup(key);
		nu_env->value = ft_strdup(value);
		nu_env->ported = ported;
		nu_env->next = NULL;
		tm_env->next = nu_env;
		return (nu_env);
	}
	if (ported == 0)
		return (tm_env);
	free(tm_env->value);
	tm_env->value = ft_strdup(value);
	return(tm_env);
}
