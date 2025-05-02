/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:37:25 by mdakni            #+#    #+#             */
/*   Updated: 2025/05/01 22:34:47 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Token_and_lex.h"

void syntax_error(token type, t_input *list)
{
    if(type == TOKEN_PIPE)
        printf("Syntax Error near unexpected Token '|'");
    if(type == TOKEN_R_RED)
        printf("Syntax Error near unexpected Token '>'");
    if(type == TOKEN_L_RED)
        printf("Syntax Error near unexpected Token '<'");
    if(type == TOKEN_R_APP)
        printf("Syntax Error near unexpected Token '>>'");
    if(type == TOKEN_L_APP)
        printf("Syntax Error near unexpected Token '<<'");
    if(type == TOKEN_AND)
        printf("Syntax Error near unexpected Token '&&'");
    if(type == TOKEN_OR)
        printf("Syntax Error near unexpected Token '||'");
    ft_lstfree(list);
    exit(EXIT_FAILURE);
}

void check_ops(t_input *list)
{
    t_input *iter;
    bool checker;

    iter = list;
    checker = false;
    while(iter)
    {
        if(iter->category == TOKEN_OP && checker == false)
            checker = true;
        else if(iter->category != TOKEN_OP && checker == true)
            checker = false;
        else if (iter->category == TOKEN_OP && checker == true)
            return(syntax_error(iter->type, list));
        
        iter = iter->next;
    }
}
// this function manages the first level of syntax checking (words, operators, delimiters)
void filter(t_input *list)
{
    check_ops(list);
}
