/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seperator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:13:20 by mdakni            #+#    #+#             */
/*   Updated: 2025/05/09 11:45:37 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Token_and_lex.h"

void handle_file(t_input *list)
{
    while(list)
    {
        if(list->red_app)
            list->next->type = TOKEN_FILE;
        list = list->next;
    }
}
void handle_cmd(t_input *list)
{
    bool check;

    check = false;
    while(list)
    {
        if(list->type == TOKEN_WORD && !check)
        {
            list->type = TOKEN_CMD;
            check = true;
        }
        if(list->type == TOKEN_PIPE || list->type == TOKEN_AND)
            check = false;
        else if(list->type == TOKEN_OR || list->type == TOKEN_O_PAR)
            check = false;
        else if(list->type == TOKEN_C_PAR)
            check = false;
        list = list->next;
    }
}

void handle_arg(t_input *list)
{
    while(list)
    {
        if(list->type == TOKEN_WORD)
            list->type = TOKEN_ARG;
        list = list->next;
    }
}

void seperator(t_input *list)
{
    handle_file(list);
    handle_cmd(list);
    handle_arg(list);
}