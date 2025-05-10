/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:28:07 by mdakni            #+#    #+#             */
/*   Updated: 2025/05/09 13:42:27 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Token_and_lex.h"

bool check_tokens(t_input *list)
{
    bool tmp;

    tmp = false;
    if(list->type == TOKEN_PIPE)
        tmp = true;
    else if(list->type == TOKEN_OR)
        tmp = true;
    else if(list->type == TOKEN_AND)
        tmp = true;
    else if(list->type == TOKEN_O_PAR)
        tmp = true;
    else if(list->type == TOKEN_C_PAR)
        tmp = true;
    else if(list->type == TOKEN_EOF)
        tmp = true;
    return tmp;
}

bool check_reds(t_input *list)
{
    bool tmp;

    tmp = false;
    if(list->type == TOKEN_L_RED)
        tmp = true;
    else if(list->type == TOKEN_R_RED)
        tmp = true;
    else if(list->type == TOKEN_L_APP)
        tmp = true;
    else if(list->type == TOKEN_R_APP)
        tmp = true;
    return tmp;
}

t_size count_nodes(t_input *list)
{
    t_size nodes;

    nodes.nodes = 0;
    nodes.size_cmd = 0;
    nodes.size_red = 0;
    while(list)
    {
        if(check_reds(list))
        {
            nodes.size_red += 2;
            list = list->next->next;
        }
        else if(!check_tokens(list))
        {
            if(list->type == TOKEN_CMD)
                nodes.nodes++;
            nodes.size_cmd++;
            if(!check_reds(list))
                list = list->next;
        }
        else if(!check_reds(list))
                list = list->next;
    }
    return nodes;
}

t_short *transformer(t_input *list)
{
    t_size nodes;
    t_short *shart;

    nodes = count_nodes(list);
    // nodes.args = ft_calloc(sizeof(char *), nodes.nodes);
    // nodes.reds = ft_calloc(sizeof(char *), nodes.nodes);
    // if(nodes.args == NULL)
    //     return NULL;
    
    (void)shart;  
    printf("\n nodes : %d, args : %d, reds : %d\n", nodes.nodes, nodes.size_cmd, nodes.size_red);
    return NULL;
}
