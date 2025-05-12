/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 00:18:21 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/12 09:15:55 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

void	env_print(t_env **env)
{
	t_env	*env_tmp;

	if (env == NULL || *env == NULL)
	{
		printf("\033[31;1mNULL\033[0m\n");
		return;
	}
	env_tmp = *env;
	while (env_tmp)
	{
		printf("%s=%s\n", env_tmp->name, env_tmp->valve);
		env_tmp = env_tmp->next;
	}
}
