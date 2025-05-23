/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:00:33 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/23 05:32:02 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
#define ENV_H

#include "../m_exec.h"

typedef struct s_env
{
	char			*key;
	char			*value;
	bool			ported;
	struct s_env	*next;
}					t_env;

t_env	*int_env(char **env);
int		 prn_env(t_env *env);
int		 fre_env(t_env *env);
int		 del_env(t_env *env, char *key);
t_env	*grp_env(t_env *env, char *key);
t_env	*add_env(t_env *env, char *key, char *value, bool ported);

#endif // ENV_H