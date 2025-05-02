/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:42:16 by mdakni            #+#    #+#             */
/*   Updated: 2025/05/01 19:00:07 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Token_and_lex.h"

void	lst_print(t_input *head)
{
	char	*data;
	t_input *og;
	int	size;

	og = head;
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
	// size = 0;
	// while (head != og)
	// {
	// 	size++;
	// 	data = head->value;
	// 	if (data == NULL)
	// 		printf("\033[1;31m%d\033[0m", 0);
	// 	else
	// 		printf("\033[1;34m%d\033[0m : \033[1;36m\"%s\"\033[0m", head->type, data);
	// 	printf("\033[1;37m -> \033[0m");
	// 	head = head->prev;
	// }
	printf("\033[1;35mNULL\033[0m");
	printf("\033[1;33m %d\033[0m\n", size);
}

void lst_assign(t_input **new, t_input **lst)
{
	t_input	*ptr;
    t_input *prev;

    prev = NULL;
	ptr = *lst;
    while (ptr->next)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    ptr->prev = prev;
	ptr->next = (*new);
	(*lst)->tail = ptr;
}

void	ft_lstadd_back(t_input **lst, char *content)
{
    t_input *new;

	new = ft_calloc(sizeof(t_input), 1);
	if (new == NULL)
		return ;
	new->value = content;
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lst_assign(&new, lst);
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
