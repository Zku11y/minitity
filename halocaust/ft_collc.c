/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 03:35:53 by oel-mado          #+#    #+#             */
/*   Updated: 2025/04/27 15:19:48 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coll.h"

void	*ft_collc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;
	size_t	t;

	i = 0;
	if (size > 0 && count >= SIZE_MAX / size)
		return (NULL);
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	if (size == 0 || count == 0)
		return (ptr);
	else
	{
		t = count * size;
		while (i < t)
			((unsigned char *)ptr)[i++] = (unsigned char)0;
	}
	// listt(ptr);
	return (ptr);
}
