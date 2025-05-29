/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:47:13 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/29 13:21:24 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bul_cmd.h"

char	*n_path(t_data *data, char *opeth)
{
	char *path;
	char *home;

	if (opeth[0] != '~')
	{
		path = ft_strdup(opeth);
		return (path);
	}
	home = gky_env(data->env, "HOME");
	path = ft_strjoin(home, &opeth[1]);
	return (path);
}

int cmd_cd(t_data *data, char *path)
{
	t_env	*pwd;

	char (*tmp), (*pmt);
	if (!data || !data->env)
		return (1);
	if (!path || path[0] == '\0')
	{
		pmt = getenv("HOME");
		tmp = ft_strdup(pmt);
	}
	else
		tmp = n_path(data, path);
	pwd = grp_env(data->env, "PWD");
	if (!pwd)
		return (free(tmp), 1);
	if (chdir(tmp))
	{
		write(2, "Error: chdir: fin ghadi??\n", 26);
		return (free(tmp), 1);
	}
	add_env(data->env, "OLDPWD", pwd->value, 1);
	add_env(data->env, "PWD", tmp, 1);
	return (free(tmp), 0);
}
