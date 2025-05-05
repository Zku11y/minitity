/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:49:13 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/05 09:52:23 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
#define HEAD_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "get_next_line/get_next_line_bonus.c"
#include "libft/libft.h"

// need alooooot of data and i need sata
typedef struct s_data
{
	t_env	*env;
}			t_data;

// idk t9dr tnf3
typedef struct s_env
{
	char	*name;
	char	*cont;
	t_env	*next;
}			t_env;

// tbh idk
int	b_pwd(t_data *data);

bool	start(char **av);

#endif // HEAD_H
