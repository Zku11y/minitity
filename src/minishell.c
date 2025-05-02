/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:16:23 by mdakni            #+#    #+#             */
/*   Updated: 2025/05/01 22:17:44 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Token_and_lex.h"

void manager(char *line)
{
    t_input *input;

    input = tokenize(line);
    lst_print(input);
    filter(input);
    printf("\e[1;32mSuccess!\e[0m\n");
    ft_lstfree(input);
}
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	size_t	s1_len;

	i = 0;
	s1_len = ft_strlen(s1);
	while (i < s1_len)
	{
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
		i++;
	}
	return (0);
}

int prompt_msg(char **line)
{
    *line = readline("░▒▓ minishell \n\e[1;44m❯\e[0m");
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

    atexit(t);
    while(1)
    {
        if(prompt_msg(&line) == 0)
            return 0;
        printf("%s\n", line);
        free(line);
    }
}