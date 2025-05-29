/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bul_cmd.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:31:29 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/29 11:41:12 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUL_CMD_H
#define BUL_CMD_H

#include "../m_exec.h"

typedef struct s_data t_data;

int	cmd_export(t_data *data, char *key, char *value);
int	cmd_unset(t_data *data, char *key);
int	cmd_echo(t_data *data, int nl, char **arg);
int	cmd_env(t_data *data);
int	cmd_pwd(t_data *data);
int cmd_cd(t_data *data, char *path);

#endif //BUL_CMD_H
