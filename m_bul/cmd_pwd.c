/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:37:43 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/25 07:50:06 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bul_cmd.h"

int	cmd_pwd(t_data *data)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		write(2, "Error: getcwd()", 15);
		return (1);
	}
	ft_putstr_fd(pwd, data->fd);
	free(pwd);
	return (0);
}
