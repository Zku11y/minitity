#include "../ex.h"

int cmd_pwd(t_env *env)
{
    char *pwd;

    if (env == NULL)
        return (1);
    pwd = gvl_env(env, "PWD");
    if (!pwd)
        return (1);
    printf("%s\n", pwd);
    free(pwd);
    return (0);
}
