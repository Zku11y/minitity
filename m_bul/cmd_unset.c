/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:48:51 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/19 16:44:13 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bul_cmd.h"

int	cmd_unset(t_env *env, char *key)
{
	if (env == NULL)
	{
		write(2, "Error: env is NULL\n", 20);
		return (1);
	}
	if (del_env(env, key))
	{
		write(2, "Error: del_env failed\n", 22);
		return (1);
	}
	return (0);
}
