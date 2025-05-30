/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:35:49 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/30 20:02:23 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bul_cmd.h"

int	cmd_echo(t_data *data, char **arg)
{
	int (i), (n), (s);
	i = 0;
	n = 0;
	s = 0;
	if (!data || !arg)
		return (1);
	if (arg[0][i++] == '-')
	{
		while (arg[0][i] == 'n')
		{
			if (arg[0][i++] == '\0')
				n = 1;
		}
	}
	while (arg[i])
	{
		if (s == 1)
			ft_putstr_fd(" ", data->fd);
		ft_putstr_fd(arg[i++], data->fd);
		s = 1;
	}
	if (n)
		ft_putstr_fd("\n", data->fd);
	return (0);
}
