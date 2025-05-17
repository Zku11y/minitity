/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:48:51 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/17 21:50:01 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ex.h"

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
