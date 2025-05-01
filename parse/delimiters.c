/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimiters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:41:27 by mdakni            #+#    #+#             */
/*   Updated: 2025/05/01 13:45:24 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Token_and_lex.h"

int handle_par(t_input **list, char *line)
{
	t_input *tmp;

	if(line[0] == '(')
	{
		ft_lstadd_back(list, ft_strdup("("));
		tmp = ft_lstlast(*list);
		tmp->type = TOKEN_O_PAR;
		tmp->category = TOKEN_DELIMITER;
		return 1;
	}
	else if(line[0] == ')')
	{
		ft_lstadd_back(list, ft_strdup(")"));
		tmp = ft_lstlast(*list);
		tmp->type = TOKEN_C_PAR;
		tmp->category = TOKEN_DELIMITER;
		return 1;
	}
	return 0;
}

int handle_quotes(t_input **list, char *line)
{
	t_input *tmp;

	if(line[0] == '\'')
	{
		ft_lstadd_back(list, ft_strdup("\'"));
		tmp = ft_lstlast(*list);
		tmp->type = TOKEN_S_QUOTE;
		tmp->category = TOKEN_DELIMITER;
		return 1;
	}
	else if(line[0] == '"')
	{
		ft_lstadd_back(list, ft_strdup("\""));
		tmp = ft_lstlast(*list);
		tmp->type = TOKEN_D_QUOTE;
		tmp->category = TOKEN_DELIMITER;
		return 1;
	}
	return 0;
}
