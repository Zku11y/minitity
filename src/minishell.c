/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:16:23 by mdakni            #+#    #+#             */
/*   Updated: 2025/05/09 12:01:14 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Token_and_lex.h"

void manager(char *line)
{
    t_input *input;
    t_short *shart;

    checker(line);
    input = tokenize(line);
    filter(input);
    seperator(input);
    lst_print(input);
    printf("\e[1;32mSuccess!\e[0m\n");
    shart = transformer(input);
    ft_lstfree(input);
}

int prompt_msg(char **line)
{
    *line = readline("░▒▓ minishell \n\e[1;44m❯\e[0m");
    add_history(*line);
    if(ft_strcmp(*line, "exit") == 0)
        return 0;
    manager(*line);
    return 1;
}
void t()
{
    system("leaks minishell");
}
int main()
{
    char *line;

    // atexit(t);
    while(1)
    {
        if(prompt_msg(&line) == 0)
            return 0;
        // printf("%s\n", line);
        free(line);
    }
}