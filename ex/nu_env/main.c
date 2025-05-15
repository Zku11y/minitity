#include "nu_env.h"

int main(int ac, char **av, char **env)
{
    t_env *n_env = NULL;

    n_env = in_env(env);
    if (n_env == NULL)
    {
        printf("\e[31;1mError: in_env failed\e[0m\n");
        return (1);
    }
    print_env(n_env);
    // free_env(n_env);
    return (0);
}
