#ifndef EX_H
#define EX_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>

#include "libft/libft.h"

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_data
{
	int				cum;
	char			*ni;
	t_env			env;
}					t_data;

// 
t_env	*int_env(char **env);
int		 prn_env(t_env *env);
int		 fre_env(t_env *env);
int		 del_env(t_env *env, char *key);
char	 *gvl_env(t_env *env, char *key);
int		 add_env(t_env *env, char *key, char *value);

int	cmd_env(t_env *env);
int	cmd_export(t_env *env, char *key, char *value);
int	cmd_pwd();
int	cmd_unset(t_env *env, char *key);

void	hnd_sig(int signum, siginfo_t *info, void *cnt);

#endif //EX_H