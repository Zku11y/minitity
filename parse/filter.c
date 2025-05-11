/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skully <skully@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:37:25 by mdakni            #+#    #+#             */
/*   Updated: 2025/05/11 22:29:32 by skully           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Token_and_lex.h"

void syntax_error(t_token type, t_input *list)
{
    if(type == TOKEN_PIPE)
        printf("Syntax Error near unexpected Token '|' ");
    if(type == TOKEN_R_RED)
        printf("Syntax Error near unexpected Token '>' ");
    if(type == TOKEN_L_RED)
        printf("Syntax Error near unexpected Token '<' ");
    if(type == TOKEN_R_APP)
        printf("Syntax Error near unexpected Token '>>' ");
    if(type == TOKEN_L_APP)
        printf("Syntax Error near unexpected Token '<<' ");
    if(type == TOKEN_AND)
        printf("Syntax Error near unexpected Token '&&' ");
    if(type == TOKEN_OR)
        printf("Syntax Error near unexpected Token '||' ");
    ft_lstfree(list);
    exit(EXIT_FAILURE);
}

bool check_pipe(t_input *list)
{
    if(list->type == TOKEN_PIPE && list->next->type == TOKEN_PIPE)
        return(false);
    return true;
}

// this function manages the first level of syntax checking (words, operators, delimiters)
void filter(t_input *list)
{
    t_input *iter;
    bool checker;

    iter = list;
    checker = false;
    while(iter)
    {
        if(check_pipe(iter) == false)
            return(syntax_error(TOKEN_PIPE, list));
        if((iter->type == TOKEN_AND || iter->type == TOKEN_OR) && (!(iter->prev->value) || !(iter->next->value)))
            return(printf("2 : %d\n", iter->index) ,syntax_error(iter->type, list));
        if((iter->type == TOKEN_R_RED || iter->type == TOKEN_L_RED) && !(iter->next->value))
            return(printf("3 : %d\n", iter->index) ,syntax_error(iter->type, list));
        if((iter->type == TOKEN_R_APP || iter->type == TOKEN_L_APP) && !(iter->next->value))
            return(printf("4 : %d\n", iter->index) ,syntax_error(iter->type, list));
        if(iter->type == TOKEN_PIPE && (!(iter->prev) || !(iter->next->value)))
            return(printf("1 : %d\n", iter->index) ,syntax_error(iter->type, list));
        if(iter->category == TOKEN_OP && checker == false && iter->type != TOKEN_PIPE)
            checker = true;
        else if(iter->category != TOKEN_OP && checker == true)
            checker = false;
        else if (iter->category == TOKEN_OP && checker == true)
            return(printf("5 : %d\n", iter->index) ,syntax_error(iter->type, list));
        iter = iter->next;
    }
}
