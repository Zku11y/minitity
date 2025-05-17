#include "ex.h"

int main(int ac, char **av, char **env)
{
    t_env *hd_env;

    hd_env = int_env(env);
    prn_env(hd_env);
    printf("\n");
    add_env(hd_env, "CUM", "amabutbluow");
    prn_env(hd_env);
    printf("\n");
    del_env(hd_env, "CUM");
    add_env(hd_env, "C0M", "amabutcum");
    prn_env(hd_env);
    printf("\n");
    del_env(hd_env, "C0M");
    prn_env(hd_env);
    printf("\n");
    fre_env(hd_env);
    return 0;
}
