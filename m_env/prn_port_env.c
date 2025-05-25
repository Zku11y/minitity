/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prn_port_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:55:21 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/25 06:54:52 by oel-mado         ###   ########.fr       */
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

int	prn_port_env(t_data *data)
{
	t_env	*n_env;

	n_env = srt_env(data->env);
	if (n_env == NULL)
	{
		write(2, "Error: prn_port_env\n", 20);
		return (1);
	}
	else
	{
		while (n_env != NULL)
		{
			ft_putstr_fd("declare -x ", data->fd);
			ft_putstr_fd(n_env->key, data->fd);
			ft_putstr_fd("=\"", data->fd);
			if (n_env->value)
				ft_putstr_fd(n_env->value, data->fd);
			ft_putstr_fd("\"\n", data->fd);
			n_env = n_env->next;
		}
	}
	return (0);
}
