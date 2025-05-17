#include "../ex.h"

int cmd_export(t_env *env, char *key, char *value)
{
    if (env == NULL)
    {
        write(2, "Error: env is NULL\n", 20);
        return (1);
    }
    if (add_env(env, key, value))
    {
        write(2, "Error: add_env failed\n", 22);
        return (1);
    }
    return (0);
}
