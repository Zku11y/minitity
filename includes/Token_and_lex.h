/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token_and_lex.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skully <skully@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:27:37 by mdakni            #+#    #+#             */
/*   Updated: 2025/05/08 19:39:58 by skully           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_AND_LEX_H
#define TOKEN_AND_LEX_H

#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
// Tokens used to categorise each word in the input string.
// R : right, L : left, S : single, D : double, O : opened, C : closed.
typedef enum s_tokens
{
    TOKEN_WORD,
    TOKEN_OP,
    TOKEN_DELIMITER,
    TOKEN_RED_APP,
    TOKEN_CMD,
    TOKEN_ARG,
    TOKEN_FILE,
    TOKEN_R_RED,
    TOKEN_L_RED,
    TOKEN_R_APP,
    TOKEN_L_APP,
    TOKEN_PIPE,
    TOKEN_O_PAR,
    TOKEN_C_PAR,
    TOKEN_AND,
    TOKEN_OR,
    TOKEN_EOF
}   t_token;

typedef struct s_nodes
{
    int index;
    t_token type;
    t_token category;
    bool red_app;
    char *value;
    struct s_nodes *next;
    struct s_nodes *prev;
    struct s_nodes *tail;
}   t_input;


t_input *tokenize(char *line);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_strndup(const char *s1, int n);
int	ft_strcmp(const char *s1, const char *s2);
void	ft_lstadd_back(t_input **lst, char *content);
t_input	*ft_lstlast(t_input *lst);
size_t	ft_strlen(const char *s);
void ft_lstfree(t_input *lst);
bool is_space(char c);
void	lst_print(t_input *head);


int handle_pipe(t_input **list, char *line);
int handle_red(t_input **list, char *line);
int handle_app(t_input **list, char *line);
int handle_and_or(t_input **list, char *line);
int handle_par(t_input **list, char *line);
int handle_quotes(t_input **list, char *line);
int handle_word(t_input **list, char *line);
bool check_limit(char *line, int i,  bool *s_quote, bool *d_quote);

void filter(t_input *list);
void checker(char *line);
void seperator(t_input *list);

#endif
