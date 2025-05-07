/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:49:13 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/07 07:44:34 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
#define HEAD_H

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

// #include "get_next_line/get_next_line_bonus.c"
#include "libft/libft.h"

// need alooooot of data and i need sata

typedef struct s_env t_env;
typedef struct s_env
{
	char	*name;
	char	*valve;
	t_env	*next;
}			t_env;

typedef struct s_data
{
	t_env	*env;
}			t_data;

// tbh idk
int		b_pwd(t_data *data);

// env
int		env_add(char *name, char *valve, t_data *data);
int		env_del(const char *name, t_data *data);
t_env	*env_init(t_data *data, char **old_env);
void	env_print(t_data *data);

bool	start(char **av);

#endif // HEAD_H
