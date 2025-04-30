/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:52:37 by mdakni            #+#    #+#             */
/*   Updated: 2025/04/30 22:34:44 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Token_and_lex.h"

bool is_space(char c)
{
	if(c == ' ' || (c >= 9 && c <= 13))
		return true;
	return false;
}

void	lst_print(t_input *head)
{
	char	*data;
	int	size;

	size = 0;
	if (!head)
		printf("\033[1;31mhead 5awi a zmr\033[0m\n");
	while (head)
	{
		size++;
		data = head->value;
		if (data == NULL)
			printf("\033[1;31m%d\033[0m", 0);
		else
			printf("\033[1;34m%d\033[0m : \033[1;36m\"%s\"\033[0m", head->type, data);
		printf("\033[1;37m -> \033[0m");
		head = head->next;
	}
	printf("\033[1;35mNULL\033[0m");
	printf("\033[1;33m %d\033[0m\n", size);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strndup(const char *s1, int n)
{
	char	*str;
	int		i;

	str = malloc(ft_strlen(s1) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && i < n)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	str = malloc(ft_strlen(s1) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

t_input	*ft_lstnew(char *content)
{
	t_input	*ptr;

	ptr = malloc(sizeof(t_input));
	if (ptr == NULL)
		return (NULL);
	ptr->value = content;
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);
}

void	ft_lstadd_back(t_input **lst, char *content)
{
	t_input	*ptr;
    t_input *prev;
    t_input *new;

    prev = NULL;
	new = malloc(sizeof(t_input));
	if (new == NULL)
		return ;
	new->value = content;
	new->next = NULL;
    ptr = *lst;
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
    while (ptr->next)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    ptr->prev = prev;
	ptr->next = new;
}

t_input	*ft_lstlast(t_input *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void ft_lstfree(t_input *lst)
{
	while(lst)
	{
		free(lst->value);
		t_input *tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	free(lst);
	lst = NULL;
}

int handle_pipe(t_input **list, char *line)
{
	if(line[0] == '|' && line[1] != '|')
	{
		printf("pipe is being handled\n");
		ft_lstadd_back(list, ft_strdup("|"));
		ft_lstlast(*list)->type = TOKEN_PIPE;
		return 1;
	}
	return 0;
}

int handle_red_app(t_input **list, char *line)
{
	if(line[0] == '>' && line[1] != '>')
	{
		ft_lstadd_back(list, ft_strdup(">"));
		ft_lstlast(*list)->type = TOKEN_R_RED;
		return 1;
	}
	else if(line[0] == '<' && line[1] != '<')
	{
		ft_lstadd_back(list, ft_strdup("<"));
		ft_lstlast(*list)->type = TOKEN_L_RED;
		return 1;
	}
	if(line[0] == '>' && line[1] == '>')
	{
		ft_lstadd_back(list, ft_strdup(">>"));
		ft_lstlast(*list)->type = TOKEN_R_APP;
		return 2;
	}
	else if(line[0] == '<' && line[1] == '<')
	{
		ft_lstadd_back(list, ft_strdup("<<"));
		ft_lstlast(*list)->type = TOKEN_L_APP;
		return 2;
	}
	return 0;
}

int handle_and_or(t_input **list, char *line)
{
	if(line[0] == '&' && line[1] == '&')
	{
		ft_lstadd_back(list, ft_strdup("&&"));
		ft_lstlast(*list)->type = TOKEN_AND;
		return 2;
	}
	else if(line[0] == '|' && line[1] == '|')
	{
		ft_lstadd_back(list, ft_strdup("||"));
		ft_lstlast(*list)->type = TOKEN_OR;
		return 2;
	}
	return 0;
}

int handle_par_quotes(t_input **list, char *line)
{
	if(line[0] == '(')
	{
		ft_lstadd_back(list, ft_strdup("("));
		ft_lstlast(*list)->type = TOKEN_O_PAR;
		return 1;
	}
	else if(line[0] == ')')
	{
		ft_lstadd_back(list, ft_strdup(")"));
		ft_lstlast(*list)->type = TOKEN_C_PAR;
		return 1;
	}
	else if(line[0] == '\'' && line[1] != '\'')
	{
		ft_lstadd_back(list, ft_strdup("\'"));
		ft_lstlast(*list)->type = TOKEN_S_QUOTE;
		return 1;
	}
	else if(line[0] == '"' && line[1] != '"')
	{
		ft_lstadd_back(list, ft_strdup("\""));
		ft_lstlast(*list)->type = TOKEN_D_QUOTE;
		return 1;
	}
	return 0;
}

int handle_word(t_input **list, char *line)
{
	int i;

	i = 0;
	while(line[i])
	{
		if(line[i] == '<' || line[i] == '>')
			break;
		if(line[i] == '|' || line[i] == '&')
			break;
		if(line[i] == '(' || line[i] == ')')
			break;
		if(line[i] == '"' || line[i] == '\'')
			break;
		if(is_space(line[i]))
			break;
		i++;
	}
	if(i > 0)
	{
		ft_lstadd_back(list, ft_strndup(line, i));
		ft_lstlast(*list)->type = TOKEN_WORD;
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
		i += handle_red_app(list, line + i);
		i += handle_par_quotes(list, line + i);
		// printf("loop here\n");
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
    lst_print(list);
    printf("\e[1;32mSuccess!\e[0m\n");
	ft_lstfree(list);
    return (NULL);
}


// ls -la | (echo "test" | cat -e) && (yes 5 || ls -la)