/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ove.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 00:59:45 by oel-mado          #+#    #+#             */
/*   Updated: 2025/04/27 01:13:24 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coll.h"

void	ove(t_coll *coll)
{
	t_coll	*the_coll;
	t_coll	*tmp_coll;

	tmp_coll = coll;
	while (tmp_coll->next_coll)
	{
		the_coll = tmp_coll;
		tmp_coll = tmp_coll->next_coll;
		free(the_coll->coll);
	}
}
