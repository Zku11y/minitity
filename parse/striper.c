/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   striper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:35:13 by mdakni            #+#    #+#             */
/*   Updated: 2025/05/26 20:57:35 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Token_and_lex.h"

int calculate_size_blyat(char *niggers)
{
    int i;
    int dick_size;

    i = 0;
    dick_size = 0;
    while(niggers[i])
    {
        if(niggers[i] == '"' || niggers[i] == '\'')
        {
            i++;
            continue;
        }
        dick_size++;
        i++;
    }
    return(dick_size + 1);
}

void striper(t_input *list)
{
    char *tmp;
    int i;
    int j;

    while(list->value)
    {
        i = 0;
        j = 0;
        tmp = ft_calloc(calculate_size_blyat(list->value), 1);
        if(tmp == NULL)
            return;
        while(list->value[i])
        {
            if(list->value[i] == '"' || list->value[i] == '\'')
            {
                i++;
                continue;
            }
            tmp[j++] = list->value[i++];
        }
        tmp[j] = '\0';
        free(list->value);
        list->value = tmp;
        list = list->next;
    }
}
