/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 23:13:09 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/07 08:28:44 by oel-mado         ###   ########.fr       */
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
	neo = NULL;
	// printf("\033[32;1min init\033[0m\n");
	// while (old_env[i])
	// 	printf("\033[1;31m%s\033[0m\n", old_env[i++]);
	// i = 0;
	j = 0;
	while (old_env[i][j] != '=' && old_env[i][j] != '\0')
		j++;
	name = ft_calloc(j, 1);
	ft_strlcpy(name, &old_env[i][0], j + 1);
	s = ft_strlen(&old_env[i][j + 1]);
	valve = ft_calloc(s, 1);
	ft_strlcpy(valve, &old_env[i][j + 1], s + 1);
	data->env = neo;
	if (env_add(name, valve, data))
		return (NULL);
	while (old_env[i])
	{
		// printf("\033[33;1menv = %s\n%d\033[0m\n", old_env[i], i);
		// j = 0;
		// while (old_env[i][j] != '=')
		// 	printf("%c", old_env[i][j++]);
		j = 0;
		while (old_env[i][j] != '=' && old_env[i][j] != '\0')
			j++;
		// printf("\n\033[33;1minit while %d\033[0m\n", j);
		name = ft_calloc(j, 1);
		ft_strlcpy(name, &old_env[i][0], j + 1);
		s = ft_strlen(&old_env[i][j + 1]);
		valve = ft_calloc(s, 1);
		ft_strlcpy(valve, &old_env[i][j + 1], s + 1);
		printf("\033[33;1m%s\033[35m=\033[33m%s\033[0m\n", name, valve);
		if (env_add(name, valve, data))
			return (NULL);
		free(name);
		free(valve);
		i++;
	}
	return (neo);
}

