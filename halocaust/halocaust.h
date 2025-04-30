/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   halocaust.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 00:52:54 by oel-mado          #+#    #+#             */
/*   Updated: 2025/04/27 18:28:05 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HALOCAUST_H
# define HALOCAUST_H

# include <stdlib.h>

// struct
typedef struct s_jews
{
	void		*jew;
	t_jews		*next_jew;
}				t_jews;

void	*ft_calloc(size_t count, size_t size);

#endif //HALOCAUST_H
