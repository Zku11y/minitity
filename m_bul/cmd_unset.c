/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:48:51 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/25 08:30:23 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bul_cmd.h"

int	cmd_unset(t_data *data, char *key)
{
	if (!data || !(data->env) || !key)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	del_env(data->env, key);
	return (0);
}
