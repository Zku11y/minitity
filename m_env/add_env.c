#include "../ex.h"

int add_env(t_env *env, char *key, char *value)
{
    t_env *nu_env;
    t_env *tm_env;
    int l;

    if (key == NULL || env == NULL)
        return (1);
    tm_env = env;
    l = ft_strlen(key);
    while (tm_env != NULL)
    {
        if (tm_env->key[l] == '\0' && ft_strncmp(tm_env->key, key, l) == 0)
        {
            free(tm_env->value);
            tm_env->value = ft_strdup(value);
            return (0);
        }
        if (tm_env->next == NULL)
            break;
        tm_env = tm_env->next;
    }
    nu_env = ft_calloc(sizeof(t_env), 1);
    nu_env->key = ft_strdup(key);
    nu_env->value = ft_strdup(value);
    nu_env->next = NULL;
    tm_env->next = nu_env;
    return (0);
}
