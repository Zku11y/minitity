#include "../ex.h"

int fre_env(t_env *env)
{
    t_env *tm_env;

    if (env == NULL)
        return (1);
    else
    {
        while (env != NULL)
        {
            free(env->key);
            free(env->value);
            tm_env = env;
            env = env->next;
            free(tm_env);
        }
    }
    return (0);
}
