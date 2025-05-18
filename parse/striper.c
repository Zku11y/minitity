/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   striper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:15:41 by mdakni            #+#    #+#             */
/*   Updated: 2025/05/18 22:33:38 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Token_and_lex.h"

void string_app(t_input *list, t_flags *check, bool flag)
{
    char *tmp;
    tmp = check->string;
    if(flag)
    {
        check->string = ft_strnjoin(check->string, list->value + check->start, (check->i - 1) - check->start);
        check->start = check->i + 1;
    }
    else
        check->string = ft_strnjoin(check->string, list->value + check->start, (check->i) - check->start);
    free(tmp);
}

void handle_CA$H(t_input *list, t_flags *check)
{
    char *tmp;
    char *tmp2;

    check->changed = true;
    check->i--;
    string_app(list, check, false);
    check->i += 2;
    check->start = check->i;
    while(ft_isalnum(list->value[check->i]) || list->value[check->i] == '_')
        check->i++;
    tmp = ft_substr(list->value, check->start, (check->i) - check->start);
    printf("\nsubstr : %s\n", tmp);
    tmp2 = getenv(tmp);
    check->string = ft_strnjoin(check->string, tmp2, ft_strlen(tmp2));
    check->start = check->i;
    check->i--;
    free(tmp);
    // free(tmp2);
}

void node_check(t_input *list, t_flags *check)
{
    if(list->value[check->i] == '"' && !check->flag_s)
    {
        if(check->flag_d)
            check->flag_d = false;
        else
            check->flag_d = true;
        check->changed = true;
        string_app(list, check, true);
    }
    else if(list->value[check->i] == '\'' && !check->flag_d)
    {
        if(check->flag_s)
            check->flag_s = false;
        else
            check->flag_s = true;
        check->changed = true;
        string_app(list, check, true);
    }
    else if(list->value[check->i] == '$' && !check->flag_s)
    {
        handle_CA$H(list, check);
    }
    else if(list->value[check->i + 1] == '\0')
        string_app(list, check, false);
}
void node_mod(t_input *list)
{
    t_flags check;

    check.changed = false;
    check.flag_d = false;
    check.flag_s = false;
    check.string = NULL;
    check.start = 0;
    check.i = 0;
    while(list->value[check.i])
    {
        node_check(list, &check);
        check.i++;
    }
    if(check.changed == true)
        list->value = check.string;
}

void striper(t_input *list)
{
    while(list->value)
    {
        if(list->type == TOKEN_L_APP)
        {
            list = list->next->next;
            continue;
        }
        // printf("im nigger!\n");
        node_mod(list);
        list = list->next;
    }
}



// void check_quotes(char *line, t_quotes *check)
// {
// 	if(line[(check->i)] == '"' && (check->quotes) != 1)
// 	{
// 		if(check->quotes == 2)
// 			check->quotes = 0;
// 		else
// 			check->quotes = 2;
// 	}
// 	else if(line[check->i] == '\'' && (check->quotes) != 2)
// 	{
// 		if(check->quotes == 1)
// 			check->quotes = 0;
// 		else
// 			check->quotes = 1;
// 	}
// }
// char  *handle_expansion(t_input *list, t_quotes *check, char *striped, int *prev)
// {
//     int j;
//     char *tmp1;

//     j = 0;
//     if(!ft_isalpha(list->value[check->i]) && list->value[check->i] != '_')
//     {
//         check->i++;
//         return("");
//     }
//     while((ft_isalnum(list->value[check->i]) || list->value[check->i] == '_') && list->value[check->i])
//         check->i++;
//     *prev = check->i;
//     tmp1 = ft_strndup(list->value + *prev, check->i - 1);
//     striped = ft_strjoin(striped, getenv(tmp1));
//     free(tmp1);
//     return striped;
// }
// char *ft_replace(t_input *list, t_quotes *check, char *striped, int *prev)
// {
//     char c;

//     striped = ft_strnjoin(striped, list->value + *prev, check->i - 1);
//     c = list->value[check->i];
//     check->i++;
//     *prev = check->i;
//     if(list->value[check->i] == '$' && check->quotes != 1 && list->value[check->i])
//         striped =  handle_expansion(list, check, striped, prev);
//     return striped;
// }
//     // else if(c == '"' || c == '\'')
//     // {
//     //     while(list->value[check->i] != c && list->value[check->i])
//     //         check->i++;
//     //     striped = ft_strnjoin(striped, list + prev, check->i - 1);
//     //     check->i++;
//     // }

// void remove_stuff(t_input *list)
// {
//     t_quotes check;
//     char *striped;
//     char c;
//     int prev;
//     int change;

//     prev = 0;
//     change = 0;
//     check.i = 0;
//     striped = NULL;
//     check.quotes = 0;
//     while(list->value[check.i])
//     {
//         printf("in the while loop...\n");
//         check_quotes(list->value, &check);
//         if((list->value[check.i] == '$' && check.quotes != 1) || list->value[check.i] == '"' || list->value[check.i] == '\'')
//         {
//             change = 1;
//             if(list->value[check.i] == '$' && check.quotes != 1)
//                 striped =  handle_expansion(list, &check, striped, &prev);
//             else
//             {
//                 striped = ft_strnjoin(striped, list->value + prev, check.i - 1);
//                 c = list->value[check.i];
//                 check.i++;
//                 prev = check.i;
//             }
//             printf("in the if statement..., : ->%s<-\n", striped);
//         }
//         check.i++;
//     }
//     if(change)
//         list->value = striped;
// }
//             // striped = ft_replace(list, &check, striped, &prev);

// void striper(t_input *list)
// {
//     while(list->value)
//     {
//         printf("im here!, : ->%s<-\n", list->value);
//         remove_stuff(list);
//         list = list->next;
//     }
// }
