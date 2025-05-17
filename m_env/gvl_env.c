#include "../ex.h"

char *gvl_env(t_env *env, char *key)
{
    t_env *tm_env;
    int l;

    if (key == NULL || env == NULL)
        return (NULL);
    tm_env = env;
    l = ft_strlen(key);
    while (tm_env != NULL)
    {
        if (tm_env->key[l] == '\0' && ft_strncmp(tm_env->key, key, l) == 0)
            return (ft_strdup(tm_env->value));
        tm_env = tm_env->next;
    }
    return (NULL);
}
