#include "head.h"

int main(int ac, char **av, char **env)
{
    t_data *data;

    printf("\033[33;1md5ol\033[0m\n");
    data = ft_calloc(sizeof(t_data), 1);
    env_init(data, env);
    printf("\033[33;1minit\033[0m\n");
    while ((data->env)->next)
		printf("%s=%s\n", (data->env)->name, (data->env)->valve);
    printf("\033[33;1msala\033[0m\n");

    return 0;
}
