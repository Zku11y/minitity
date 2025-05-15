



#ifndef NU_ENV_H
#define NU_ENV_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../libft/libft.h"

typedef struct s_env t_env;

typedef struct s_env
{
    char *name;
    char *vale;
    t_env *next;
}       t_env;

t_env *in_env(char **env);
void print_env(t_env *env);




#endif //NU_ENV_H
