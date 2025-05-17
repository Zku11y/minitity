/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hnd_sig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:02:56 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/17 19:10:01 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ex.h"

void	hnd_sig(int signum, siginfo_t *info, void *cnt)
{
	(void)cnt;
	(void)info;
	if (signum == SIGINT)
	{
		// if (prompt_msg())
		// 	write(2, "Error: prompt_msg() dead\n", 7);
		;;
	}
	else if (signum == SIGQUIT)
		;;
}
