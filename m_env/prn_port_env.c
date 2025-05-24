/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prn_port_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:55:21 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/24 17:19:05 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_env	*cpy_env(t_env *env)
{
	t_env	*h_env;
	t_env	*o_env;
	int		s;

	o_env = env;
	h_env = NULL;
	if (o_env->key == NULL)
		return (NULL);
	while (o_env)
	{
		add_env(h_env, o_env->key, o_env->value, o_env->ported);
		o_env = o_env->next;
	}
	return (h_env);
}

t_env	*srt_env(t_env *env)
{
	t_env	*n_env;

	n_env = cpy_env(env);
	// CODE TAY SORTI
	return (n_env);
}

int	prn_port_env(t_env *env)
{
	t_env	*n_env;

	n_env = srt_env(env);
	if (env == NULL)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		while (n_env != NULL)
		{
			printf("declare -x %s=\"%s\"\n", n_env->key, n_env->value);
			n_env = n_env->next;
		}
	}
	return (0);
}
