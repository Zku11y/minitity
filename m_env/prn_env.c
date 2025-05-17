#include "../ex.h"

int prn_env(t_env *env)
{
    t_env *n_env;

    n_env = env;
    if (env == NULL)
    {
        printf("Error\n");
        return (1);
    }
    else
    {
        while (n_env != NULL)
        {
            printf("%s=%s\n", n_env->key, n_env->value);
            n_env = n_env->next;
        }
    }
    return (0);
}
