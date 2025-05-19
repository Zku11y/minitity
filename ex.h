#ifndef EX_H
#define EX_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>

#include "libft/libft.h"
#include "m_bul/bul_cmd.h"
#include "m_env/env.h"

typedef struct s_data
{
	int				cum;
	char			*ni;
	t_env			env;
}					t_data;

void	hnd_sig(int signum, siginfo_t *info, void *cnt);

#endif //EX_H