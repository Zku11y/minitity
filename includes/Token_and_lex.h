/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token_and_lex.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:27:37 by mdakni            #+#    #+#             */
/*   Updated: 2025/04/30 22:44:56 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
// Tokens used to categorise each word in the input string.
// R : right, L : left, S : single, D : double, O : opened, C : closed.
typedef enum Tokens
{
    TOKEN_WORD,
    TOKEN_CMD,
    TOKEN_ARG,
    TOKEN_FILE,
    TOKEN_R_RED,
    TOKEN_L_RED,
    TOKEN_R_APP,
    TOKEN_L_APP,
    TOKEN_PIPE,
    TOKEN_S_QUOTE,
    TOKEN_D_QUOTE,
    TOKEN_O_PAR,
    TOKEN_C_PAR,
    TOKEN_AND,
    TOKEN_OR,
    TOKEN_EOF
}   token;

typedef struct nodes
{
    int index;
    token type;
    char *value;
    struct nodes *next;
    struct nodes *prev;
}   t_input;

t_input *tokenize(char *line);
char	*ft_strdup(const char *s1);
t_input	*ft_lstnew(char *content);
void	ft_lstadd_back(t_input **lst, char *content);
size_t	ft_strlen(const char *s);