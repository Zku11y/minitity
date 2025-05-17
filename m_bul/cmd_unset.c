#include "../ex.h"

int cmd_unset(t_env *env, char *key)
{
    if (env == NULL)
    {
        write(2, "Error: env is NULL\n", 20);
        return (1);
    }
    if (del_env(env, key))
    {
        write(2, "Error: del_env failed\n", 22);
        return (1);
    }
    return (0);
}
