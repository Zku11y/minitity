/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prn_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:55:21 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/17 21:55:53 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ex.h"

int	prn_env(t_env *env)
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
