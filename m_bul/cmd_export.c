/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:17:57 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/25 07:53:08 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bul_cmd.h"

int	cmd_export(t_data *data, char *key, char *value)
{
	if (!(data->env))
		return (1);
	if (!key && !value)
		prn_port_env(data);
	else if (!key)
		return (1);
	if ((key[0] > 'z' && key[0] < 'a') || (key[0] > 'Z' && key[0] < 'A')
			|| key[0] != '_')
		return (1);
	if (!value)
		add_env(data->env, key, NULL, 0);
	else
		add_env(data->env, key, value, 1);
	return (0);
}
