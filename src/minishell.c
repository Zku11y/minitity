/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skully <skully@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:16:23 by mdakni            #+#    #+#             */
/*   Updated: 2025/05/30 14:50:00 by skully           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Token_and_lex.h"

void manager(char *line)
{
    t_input *input;
    t_short *shart;

    // checker(line);
    input = tokenize(line);
    filter(input);
    seperator(input);
    input = money_expansion(input);
    input = star_expansion(input);
    striper(input);
    shart = last_lst_creater(input);
    lst_print2(shart);
    // lst_print(input);
    // printf("\e[1;32mCums!\e[0m\n");
    // shart = transformer(input);
    ft_lstfree(input);
    ft_lstfree_2(shart);
}

int prompt_msg()
{
    char *line;
    line = readline("\e[1;32m❯ \e[0m");
    if (!line)
    {
        write(1, "exit\n", 5);
        free(line);
        exit(0);
    }
    add_history(line);
    if(ft_strcmp(line, "exit") == 0)
        return 0;
    manager(line);
    free(line);
    return 1;
}
void t()
{
    system("leaks minishell");
}

// void    hnd_sig(int signum, siginfo_t *info, void *cnt);
    
int main()
{
    // printf("\e[1;31mam about blauw\e[0m\n");
    // struct sigaction    s_sig;

    // atexit(t);
    // ft_memset(&s_sig, 0, sizeof(s_sig));
    // s_sig.sa_sigaction = hnd_sig;
    // s_sig.sa_flags = SA_SIGINFO;
    // sigaction(SIGINT, &s_sig, NULL);
    // sigaction(SIGQUIT, &s_sig, NULL);
    while(1)
    {
        if(prompt_msg() == 0)
            return 0;
        // printf("%s\n", line);
    }
}