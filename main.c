#include "m_exec.h"

int main(int ac, char **av, char **env)
{
	t_data *data;

	data = ft_calloc(sizeof(data), 1);
	data->fd = 1;
	data->env = int_env(env);
	prn_port_env(data);
	fre_env(data->env);
	free(data);
	return 0;
}
