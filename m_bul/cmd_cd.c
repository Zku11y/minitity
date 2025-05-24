/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:47:13 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/24 21:50:31 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bul_cmd.h"

int cmd_cd(t_env *env, char *path)
{
	t_env	*pwd;
	char	*tmp;

	if (!env)
		return (1);
	if (!path)
		tmp = getenv("HOME");
	else
		tmp = path;
	pwd = grp_env(env, "PWD");
	if (!pwd)
		return (1);
	if (chdir(tmp))
	{
		write(2, "Error: chdir: fin ghadi??", 25);
		return (1);
	}
	add_env(env, "OLDPWD", pwd->value, 1);
	add_env(env, "PWD", tmp, 1);
	return (0);
}
