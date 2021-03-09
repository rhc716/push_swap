/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:41:22 by hroh              #+#    #+#             */
/*   Updated: 2021/03/09 21:44:31 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_action_rra(t_env *env, int mute)
{
	env->b_cnt = env->b_cnt;
	(void)mute;
	write(STDOUT_FILENO, "rra\n", 3);
}

void	ft_action_rrb(t_env *env, int mute)
{
	env->b_cnt = env->b_cnt;
	(void)mute;
	write(STDOUT_FILENO, "rrb\n", 3);
}

void	ft_action_rrr(t_env *env)
{
	env->b_cnt = env->b_cnt;
	write(STDOUT_FILENO, "rrr\n", 3);
}
