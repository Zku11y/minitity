/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_exc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:53:01 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/30 22:56:09 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX_EXC_H
#define EX_EXC_H

#include "../m_exec.h"

typedef struct s_data t_data;

int	ex_rish(t_data *data, char **arg);
int	ex_sunau(t_data *data, char **arg);

#endif // EX_EXC_H
