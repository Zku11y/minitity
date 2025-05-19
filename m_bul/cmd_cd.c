/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:47:13 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/19 16:43:34 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bul_cmd.h"

int cmd_cd(t_env *env, char *path)
{
	t_env	*old_pwd;
	t_env	*pwd;
	char	*tmp;

	if (!env || !path)
		return (1);
	if (chdir(path))
	{
		write(2, "Error: cd\n", 10);
		return (1);
	}
	pwd = grp_env(env, "PWD");
	if (pwd == NULL)
		pwd = add_env(env, "PWD", path);
	old_pwd = grp_env(env, "OLDPWD");
	if (old_pwd != NULL)
		free(old_pwd->value);
	else
		pwd = add_env(env, "OLDPWD", NULL);
	old_pwd->value = pwd->value;
	pwd->value = ft_strdup(path);
	return (0);
}
