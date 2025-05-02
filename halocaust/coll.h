/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coll.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 00:52:54 by oel-mado          #+#    #+#             */
/*   Updated: 2025/04/27 18:28:05 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLL_H
# define COLL_H

# include <stdlib.h>

// struct
typedef struct s_col
{
	void		*vd;
	t_col		*next_clo;
}				t_col;

void	*ft_collc(size_t count, size_t size);

#endif //COLL_H
