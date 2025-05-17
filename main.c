#include "ex.h"

int main(int ac, char **av, char **env)
{
	t_env *hd_env;

	hd_env = int_env(env);
	fre_env(hd_env);
	return 0;
}
