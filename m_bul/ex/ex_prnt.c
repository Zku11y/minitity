/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_prnt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:55:21 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/19 16:44:55 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bul_cmd.h"

int	ex_prnt(t_env *env)
{
	t_env	*n_env;

	n_env = env;
	if (env == NULL)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		while (n_env != NULL)
		{
			printf("%s=%s\n", n_env->key, n_env->value);
			n_env = n_env->next;
		}
	}
	return (0);
}
