/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:41:24 by mdakni            #+#    #+#             */
/*   Updated: 2025/05/01 13:45:50 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Token_and_lex.h"

int handle_pipe(t_input **list, char *line)
{
	t_input *tmp;

	if(line[0] == '|' && line[1] != '|')
	{
		printf("pipe is being handled\n");
		ft_lstadd_back(list, ft_strdup("|"));
		tmp = ft_lstlast(*list);
		tmp->type = TOKEN_PIPE;
		tmp->category = TOKEN_OP;
		return 1;
	}
	return 0;
}

int handle_red(t_input **list, char *line)
{
	t_input *tmp;

	if(line[0] == '>' && line[1] != '>')
	{
		ft_lstadd_back(list, ft_strdup(">"));
		tmp = ft_lstlast(*list);
		tmp->type = TOKEN_R_RED;
		tmp->category = TOKEN_OP;
		return 1;
	}
	else if(line[0] == '<' && line[1] != '<')
	{
		ft_lstadd_back(list, ft_strdup("<"));
		tmp = ft_lstlast(*list);
		tmp->type = TOKEN_L_RED;
		tmp->category = TOKEN_OP;
		return 1;
	}
	return 0;
}

int handle_app(t_input **list, char *line)
{
	t_input *tmp;

	if(line[0] == '>' && line[1] == '>')
	{
		ft_lstadd_back(list, ft_strdup(">>"));
		tmp = ft_lstlast(*list);
		tmp->type = TOKEN_R_APP;
		tmp->category = TOKEN_OP;
		return 2;
	}
	else if(line[0] == '<' && line[1] == '<')
	{
		ft_lstadd_back(list, ft_strdup("<<"));
		tmp = ft_lstlast(*list);
		tmp->type = TOKEN_L_APP;
		tmp->category = TOKEN_OP;
		return 2;
	}
	return 0;
}

int handle_and_or(t_input **list, char *line)
{
	t_input *tmp;

	if(line[0] == '&' && line[1] == '&')
	{
		ft_lstadd_back(list, ft_strdup("&&"));
		tmp = ft_lstlast(*list);
		tmp->type = TOKEN_AND;
		tmp->category = TOKEN_OP;
		return 2;
	}
	else if(line[0] == '|' && line[1] == '|')
	{
		ft_lstadd_back(list, ft_strdup("||"));
		tmp = ft_lstlast(*list);
		tmp->type = TOKEN_OR;
		tmp->category = TOKEN_OP;
		return 2;
	}
	return 0;
}
