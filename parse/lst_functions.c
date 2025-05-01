/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:42:16 by mdakni            #+#    #+#             */
/*   Updated: 2025/05/01 13:46:44 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Token_and_lex.h"

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
