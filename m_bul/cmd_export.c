/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:17:57 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/17 19:30:38 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ex.h"

int cmd_export(t_env *env, char *key, char *value)
{
    if (env == NULL)
    {
        write(2, "Error: env is NULL\n", 19);
        return (1);
    }
    if (add_env(env, key, value))
    {
        write(2, "Error: add_env failed\n", 21);
        return (1);
    }
    return (0);
}
