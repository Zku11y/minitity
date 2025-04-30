/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   train.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 01:12:09 by oel-mado          #+#    #+#             */
/*   Updated: 2025/04/27 18:19:58 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "halocaust.h"

void	train(void *jew)
{
	t_jews	*jews;

	jews = malloc (sizeof(t_jews));
	if (!jews)
		ult();
	jews->next_jew = NULL;
}
