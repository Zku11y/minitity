/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prn_port_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:55:21 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/29 08:38:49 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_env	*cpy_env(t_env *env)
{
	int i;

	i = 0;
	t_env (*hd_env), (*nu_env), (*tm_env), (*og_env);
	nu_env = NULL;
	if (!env || !env->key)
		return (NULL);
	og_env = env;
	while(og_env)
	{
		nu_env = ft_calloc(sizeof(t_env), 1);
		nu_env->key = ft_strdup(og_env->key);
		nu_env->value = ft_strdup(og_env->value);
		nu_env->ported = og_env->ported;
		nu_env->next = NULL;
		if (i == 0)
			hd_env = nu_env;
		else
			tm_env->next = nu_env;
		i = 1;
		tm_env = nu_env;
		og_env = og_env->next;
	}
	return (hd_env);
}

t_env	*srt_env(t_env *env)
{
	t_env	*n_env;
	// t_env	*curr;
	// char	*tmp_key;
	// char	*tmp_val;
	// int		tmp_ported;
	// int		sorted;

	n_env = cpy_env(env);
	// if (!n_env)
	// 	return (NULL);

	// sorted = 0;
	// while (!sorted)
	// {
	// 	sorted = 1;
	// 	curr = n_env;
	// 	while (curr && curr->next)
	// 	{
	// 		if (ft_strcmp(curr->key, curr->next->key) > 0)
	// 		{
	// 			// Swap key
	// 			tmp_key = curr->key;
	// 			curr->key = curr->next->key;
	// 			curr->next->key = tmp_key;
	// 			// Swap value
	// 			tmp_val = curr->value;
	// 			curr->value = curr->next->value;
	// 			curr->next->value = tmp_val;
	// 			// Swap ported
	// 			tmp_ported = curr->ported;
	// 			curr->ported = curr->next->ported;
	// 			curr->next->ported = tmp_ported;

	// 			sorted = 0;
	// 		}
	// 		curr = curr->next;
	// 	}
	// }
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
	printf("\033[1;33m>////<\033[0m\n");
	fre_env(n_env);
	return (0);
}
