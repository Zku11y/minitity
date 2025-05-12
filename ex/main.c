#include "head.h"

int	main(int ac, char **av, char **env)
{
	t_data	*data;
	t_env	**head;

	printf("\033[33;1md5ol\033[0m\n");
	data = ft_calloc(sizeof(t_data), 1);
	printf("\033[33;1minit\033[0m\n");
	head = env_init(env);
	printf("\033[34;1mYO\033[0m\n");
	// env_add("HIII :3", ">////<", head);
	if (head && *head && (*head)->next)
		printf("\033[34;1m%s\033[0m\n", (*head)->next->name);
	else
		printf("\033[31;1mhead, *head, or (*head)->next is NULL\033[0m\n");

	// env_add("FUCK", "NIGGERS", head);
	// env_add("YO", "GURT", head);
	// env_add("GURT", "YO", head);
	// env_print(head);
	// env_del("HIII :3", head);
	// env_print(head);
	printf("\033[33;1msala\033[0m\n");

	return 0;
}
