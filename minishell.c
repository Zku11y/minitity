/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:16:23 by mdakni            #+#    #+#             */
/*   Updated: 2025/05/29 10:48:07 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_exec.h"

static void hnd_sig(int sig)
{
    (void)sig;
  write(1, "\n", 1);
  rl_replace_line("", 0);
  rl_on_new_line();
  rl_redisplay();
}

int prompt_msg()
{
    char *line;

    line = readline("\e[1;32m❯ \e[0m");
    if (!line)
    {
        write(1, "exit\n", 5);
        free(line);
        exit(69);
    }
    printf("%s\n", line);
    if(ft_strncmp(line, "exit", 5) == 0 || ft_strncmp(line, "exit ", 5) == 0)
        return (free(line), 0);
    free(line);
    return 1;
}

int main()
{
    printf("\e[1;31mam about blauw\e[0m\n");

    signal(SIGINT, hnd_sig);
    signal(SIGQUIT, SIG_IGN);
    while(1)
    {
        if(prompt_msg() == 0)
            return 0;
        printf("\n");
    }
}
