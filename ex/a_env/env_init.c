/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 23:13:09 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/09 18:37:32 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

t_env	*env_init(t_data *data, char **old_env)
{
	int		i;
	int		j;
	char	*name;
	char	*valve;
	size_t	s;
	t_env	*neo;

	i = 0;
	j = 0;
	neo = ft_calloc(sizeof(t_env), 1);
	while (old_env[i][j] != '=' && old_env[i][j] != '\0')
		j++;
	s = ft_strlen(&old_env[i][j + 1]);
	name = ft_calloc(j, 1);
	valve = ft_calloc(s, 1);
	ft_strlcpy(name, &old_env[i][0], j + 1);
	ft_strlcpy(valve, &old_env[i][j + 1], s + 1);
	neo->name = name;
	neo->valve = valve;
	neo->next = NULL;
	data->env = neo;
	env_add(name, valve, data);
	i++;
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
		env_add(name, valve, data);
		i++;
	}
	return (neo);
}

