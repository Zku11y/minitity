#include "head.h"

int	main(int ac, char **av, char **env)
{
	t_data	*data;
	t_env	*n_env;

	printf("\033[33;1md5ol\033[0m\n");
	data = ft_calloc(sizeof(t_data), 1);
	env_init(data, env);
	printf("\033[33;1minit\033[0m\n");
	n_env = data->env;
	env_add("HIII :3", ">////<", data);
	env_add("FUCK", "NIGGERS", data);
	env_add("YO", "GURT", data);
	env_add("GURT", "YO", data);
	while (n_env)
	{
			printf("\033[1;32m%s\033[34m=\033[35m%s\033[0m\n", n_env->name, n_env->valve);
		n_env = n_env->next;
	}
	env_del("HIII :3", data);
	n_env = data->env;
	while (n_env)
	{
			printf("\033[1;32m%s\033[34m=\033[35m%s\033[0m\n", n_env->name, n_env->valve);
		n_env = n_env->next;
	}
	printf("\033[33;1msala\033[0m\n");

	return 0;
}
