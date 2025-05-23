/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_exec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 05:18:51 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/23 05:28:47 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_EXEC_H
#define M_EXEC_H

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>

#include "libft/libft.h"
#include "m_bul/bul_cmd.h"
#include "m_env/env.h"

typedef struct s_data
{
	int				fd;
	int				ex;
	t_env			env;
}					t_data;

void	hnd_sig(int signum, siginfo_t *info, void *cnt);

#endif // M_EXEC_H