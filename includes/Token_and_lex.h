/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token_and_lex.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skully <skully@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:27:37 by mdakni            #+#    #+#             */
/*   Updated: 2025/05/23 22:56:51 by skully           ###   ########.fr       */
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
#include <signal.h>


// Tokens used to categorise each word in the input string.
// R : right, L : left, S : single, D : double, O : opened, C : closed.
typedef enum s_tokens
{
    TOKEN_WORD,
    TOKEN_OP,
    TOKEN_RED_APP,
    TOKEN_DELIMITER,
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
    int quotes; // 0 : no problems, 1 : open single quotes, 2 : open double quotes
    int strip;
    t_token type;
    t_token category;
    bool red_app;
    bool expand;
    char *value;
    struct s_nodes *next;
    struct s_nodes *prev;
    struct s_nodes *tail;
}   t_input;

typedef struct s_latest
{
    char **args;
    char **reds; // ls -la | grep 'x' > outfile  -------- args == [ls] [la]
    struct s_latest *next;
    struct s_latest *prev;
    struct s_latest *tail;
}   t_short;

typedef struct s_size
{
    int nodes;
    int size_cmd;
    int size_red;
}   t_size;

typedef struct s_quotes
{
    int i;
    int quotes;
    int remove; // 0 : no problems, 1 : open single quotes, 2 : open double quotes
    bool expand;
}   t_quotes;

typedef struct s_flags
{
    char *string;
    char *expand;
    int quotes;
    int start;
    int end;
    int d_start;
    int d_end;
} t_flags;

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
int prompt_msg();
void ft_lstfree_2(t_short *lst);
t_short	*ft_lstlast_2(t_short *lst);
void	ft_lstadd_back_2(t_short **lst, char **args, char **reds);
void lst_assign_2(t_short **new, t_short **lst);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strnjoin(char *s1, char *s2, int n);
int	ft_isalpha(int c);
int	ft_isalnum(int c);
int handle_pipe(t_input **list, char *line);
int handle_red(t_input **list, char *line);
int handle_app(t_input **list, char *line);
int handle_quotes(t_input **list, char *line);
int handle_word(t_input **list, char *line);
bool check_limit(char *line, t_quotes *check);
char	*ft_substr(char const *s, unsigned int start, size_t len);

void filter(t_input *list);
void checker(char *line);
void seperator(t_input *list);
t_short *transformer(t_input *list);
t_input *striper(t_input *list);
char	**ft_split(char const *s);
#endif
