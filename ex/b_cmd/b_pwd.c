/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_pwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:05:34 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/05 09:49:32 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

int	b_pwd(t_data *data)
{
	int	size;

	size = 0;
	if (!(data->env)->cont)
		return 1;
	size = ft_strlen((data->env)->cont);
	if (!size)
		return 1;
	if (write(1, (data->env)->cont, size) == -1)
		return 1;
	return 0;	
}
