#include "nu_env.h"

t_env *in_env(char **env)
{
    t_env *n_env;
    t_env *r_env;
    t_env *h_env;
    int i;
    int j;

    i = 0;
    j = 0;
    h_env = n_env;
    while (env[i])
    {
        j = 0;
        r_env = ft_calloc(sizeof(r_env), 1);
        while (env[i][j] != '=' && env[i][j] != '\0')
            j++;
        r_env->name = ft_calloc(sizeof(char), j + 1);
        ft_strlcpy(r_env->name, env[i], j);
        r_env->name[j] = '\0';
        r_env->vale = ft_strdup(env[i] + j + 1);
        n_env->next = r_env;
        r_env->next = NULL;
        n_env = r_env;
        i++;
    }
    return (h_env);
}
