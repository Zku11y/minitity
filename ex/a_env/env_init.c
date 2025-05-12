/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 23:13:09 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/12 08:24:32 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

t_env	**env_init(char **old_env)
{
	int		i;
	int		j;
	size_t	s;
	t_env	**head;
	char	*valve;
	char	*name;

	i = 0;
	j = 0;
	head = NULL;
	while (old_env[i])
	{
		j = 0;
		while (old_env[i][j] != '=' && old_env[i][j] != '\0')
			j++;
		s = ft_strlen(&old_env[i][j + 1]);
		name = ft_calloc(j, 1);
		valve = ft_calloc(s, 1);
		ft_strlcpy(name, &old_env[i][0], j + 1);
		ft_strlcpy(valve, &old_env[i][j + 1], s + 1);
		env_add(name, valve, head);
		i++;
	}
	return (head);
}

