#include "../ex.h"

int cmd_env(t_env *env)
{
    if (env == NULL)
    {
        write(2, "Error: env is NULL\n", 20);
        return (1);
    }
    if (print_env(env))
    {
        write(2, "Error: print_env failed\n", 24);
        return (1);
    }
    return (0);
}
