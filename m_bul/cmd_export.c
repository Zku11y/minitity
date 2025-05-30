/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:17:57 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/30 22:47:02 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bul_cmd.h"

char *key_gen(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '=' && arg[i] != '\0')
	{
		if (!ft_isalpha(arg[i]) && arg[i] != '_')
			return (NULL);
		i++;
	}
	return (ft_strndup(arg, i));
}

char	*val_gen(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '=' && arg[i] != '\0')
		i++;
	return (ft_strdup(&arg[i + 1]));
}

int	cmd_export(t_data *data, char **arg)
{
	int (i), (s);
	char (*key), (*val);
	i = 0;
	s = 0;
	if (!data || !data->env)
		return (1);
	if (!arg || arg[0][0] == '\0')
		return (prn_port_env(data), 0);
	while (arg[i])
	{
		key = key_gen(arg[i]);
		if (!key)
			s = 1;
		else
		{
			val = val_gen(arg[i]);
			if (!val || val[0] == '\0')	
				add_env(data->env, key, NULL, 0);
			else
				add_env(data->env, key, val, 1);
		}
		i++;
	}
	return (free(key), free(val), s);
}
