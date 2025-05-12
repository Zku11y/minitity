/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 07:05:06 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/12 09:19:33 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

int	env_del(const char *name, t_env **head)
{
	int 	i;
	size_t	size;
	t_env	*env_tmp;
	t_env	*env_old_tmp;
	i = 0;
	size = ft_strlen(name) + 1;
	printf("\033[32;1mZBI\033[0m\n");
	env_tmp = *head;
	while (ft_strncmp(env_tmp->name, name, size) && env_tmp)
	{
		env_old_tmp = env_tmp;
		env_tmp = env_tmp->next;
	}
	if (!env_tmp)
		return (1);
	if (!env_old_tmp)
		*head = env_tmp->next;
	else
		env_old_tmp->next = env_tmp->next;
	free(env_tmp->name);
	free(env_tmp->valve);
	free(env_tmp);
	return (0);
}
