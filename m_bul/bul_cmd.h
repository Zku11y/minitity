/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bul_cmd.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:31:29 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/24 21:53:09 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUL_CMD_H
#define BUL_CMD_H

#include "../m_exec.h"

typedef struct s_ex
{
	char			*key;
	char			*val;
	char	 		*sta;
	struct s_ex		*nxt;
}					t_ex;

int	cmd_export(t_env *env, char *key, char *value);
int	cmd_unset(t_env *env, char *key);
int	cmd_echo(t_data *data, int nl, char **arg);
int	cmd_env(t_env *env);
int	cmd_pwd();

#endif //BUL_CMD_H
