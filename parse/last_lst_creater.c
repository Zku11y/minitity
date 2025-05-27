/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_lst_creater.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:35:00 by mdakni            #+#    #+#             */
/*   Updated: 2025/05/27 19:23:42 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Token_and_lex.h"

t_blah check_ambiguous(t_input *lst, t_blah blah)
{
    if(lst->type == TOKEN_FILE && lst->next)
    {
        if(lst->next->type == TOKEN_FILE)
            blah.ambiguous = true;
    }
    if(lst->red_app == true)
        blah.reds++;
    if(lst->type == TOKEN_FILE)
        blah.reds++;
    if(lst->type == TOKEN_ARG)
        blah.args++;
    if(lst->type == TOKEN_CMD)
        blah.args++;
    return blah;
}

void assign_strings(t_blah *blah, t_input *lst)
{
    blah->args_i = 0;
    blah->reds_i = 0;
    while(lst && lst->value)
    {
        if(lst->type == TOKEN_CMD)
            blah->args2[blah->args_i++] = lst->value;
        else if(lst->type == TOKEN_ARG)
            blah->args2[blah->args_i++] = lst->value;
        else if(lst->red_app == true)
            blah->reds2[blah->reds_i++] = lst->value;
        else if(lst->type == TOKEN_FILE)
            blah->reds2[blah->reds_i++] = lst->value;
        lst = lst->next;
    }
    blah->args2[blah->args_i] = NULL;
    blah->reds2[blah->reds_i] = NULL;
}

void create_node(t_blah *blah, t_input *head)
{
    blah->args2 = ft_calloc(blah->args + 1, sizeof(char *));
    blah->reds2 = ft_calloc(blah->reds + 1, sizeof(char *));
    // while(lst->prev)
    //     lst = lst->prev;
    seperator(head);
    lst_print(head);
    assign_strings(blah, head);
}

t_short *last_lst_creater(t_input *lst)
{
    t_blah blah;
    t_input *head;
    t_input *tail;
    t_short *new_lst;

    new_lst = NULL;
    while(lst)
    {
        blah.ambiguous = false;
        blah.args = 0;
        blah.reds = 0;
        head = lst;
        while(lst->value && lst->type != TOKEN_PIPE)
        {
            blah = check_ambiguous(lst, blah);
            lst = lst->next;
        }
        tail = lst->next;
        lst->next = NULL;
        create_node(&blah, head);
        ft_lstadd_back_2(&new_lst, blah);
        lst = tail;
    }
    return new_lst;
}

// find a way to free all cut lsts