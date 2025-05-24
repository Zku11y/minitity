/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:17:57 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/24 21:56:55 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bul_cmd.h"

int	ex_so(t_env *ex)
{
	prn_ex(ex);
	return (0);
}

int	cmd_export(t_env *env, char *key, char *value)
{
	if (!key && !value)
		ex_so(env);
	if ((key[0] > 'z' && key[0] < 'a') || (key[0] > 'Z' && key[0] < 'A')
			|| key[0] != '_')
		return (1);
	if (env == NULL)
	{
		write(2, "Error: env is NULL\n", 19);
		return (1);
	}
	if (add_env(env, key, value, 1))
	{
		write(2, "Error: add_env failed\n", 21);
		return (1);
	}
	return (0);
}
