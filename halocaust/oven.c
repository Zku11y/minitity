/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oven.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 00:59:45 by oel-mado          #+#    #+#             */
/*   Updated: 2025/04/27 01:13:24 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "halocaust.h"

void	oven(t_jews *jwes)
{
	t_jews	*the_jew;
	t_jews	*tmp_jew;

	tmp_jew = jwes;
	while (tmp_jew->next_jew)
	{
		the_jew = tmp_jew;
		tmp_jew = tmp_jew->next_jew;
		free(the_jew->jew);
	}
}
