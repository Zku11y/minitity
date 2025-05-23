/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hnd_sig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:02:56 by oel-mado          #+#    #+#             */
/*   Updated: 2025/05/23 05:19:59 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../m_exec.h"

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
