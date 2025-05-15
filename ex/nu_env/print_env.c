
#include "nu_env.h"

void print_env(t_env *env)
{
    t_env *tmp;

    tmp = env->next;
    while (tmp)
    {
        printf("\e[33;1m%s\e[1;35m=\e[1;34m%s\e[0m\n", tmp->name, tmp->vale);
        tmp = tmp->next;
    }
}
