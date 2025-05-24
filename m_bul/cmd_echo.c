/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:35:49 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/24 21:56:03 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bul_cmd.h"

int	cmd_echo(t_data *data, int nl, char **arg)
{
	int i;
	int s;

	i = 0;
	s = 0;
	if (!data || !arg)
		return (1);
	while (arg[i])
	{
		if (s == 1)
			ft_putstr_fd(" ", data->fd);
		ft_putstr_fd(arg[i], data->fd);
		s = 1;
		i++;
	}
	if (nl)
		ft_putstr_fd("\n", data->fd);
	return (0);
}
