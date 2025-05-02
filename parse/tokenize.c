/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skully <skully@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:52:37 by mdakni            #+#    #+#             */
/*   Updated: 2025/05/02 02:47:21 by skully           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Token_and_lex.h"

bool check_limit(char *line, int i)
{
	if(line[i] == '<' || line[i] == '>')
		return (true);
	else if(line[i] == '|' || (line[i] == '&' && line[i + 1] == '&'))
		return (true);
	else if(line[i] == '(' || line[i] == ')')
		return (true);
	else if(line[i] == '"' || line[i] == '\'')
		return (true);
	else if(is_space(line[i]))
		return (true);
	return (false);
}
int handle_word(t_input **list, char *line)
{
	int i;

	i = 0;
	while(line[i])
	{
		if (check_limit(line, i))
			break;
		i++;
	}
	if(i > 0)
	{
		ft_lstadd_back(list, ft_strndup(line, i));
		ft_lstlast(*list)->category = TOKEN_WORD;
	}
	if(!line[i])
	{
		ft_lstadd_back(list, NULL);
		ft_lstlast(*list)->type = TOKEN_EOF;
	}
	return i;
}

void assign_tokens(t_input **list, char *line)
{
	int i;

	i = 0;
	while(line[i])
	{
		while(is_space(line[i]))
			i++;
		i += handle_pipe(list, line + i);
		i += handle_and_or(list, line + i);
		i += handle_red(list, line + i);
		i += handle_app(list, line + i);
		i += handle_quotes(list, line + i);
		i += handle_par(list, line + i);
		// printf("i = %d\n", i);
		i += handle_word(list, line + i);
	}
}

t_input *tokenize(char *line)
{
    t_input *list;
    int i;

    list = NULL;
	assign_tokens(&list, line);
    i = 0;
	t_input *tmp = list;
	while(tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
    return (list);
}


// ls -la | (echo "test" | cat -e) && (yes 5 || ls -la)