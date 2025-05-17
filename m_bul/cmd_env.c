/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:17:29 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/17 19:31:16 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ex.h"

int	cmd_env(t_env *env)
{
	if (env == NULL)
	{
		write(2, "Error: env is NULL\n", 19);
		return (1);
	}
	if (print_env(env))
	{
		write(2, "Error: print_env failed\n", 23);
		return (1);
	}
	return (0);
}
