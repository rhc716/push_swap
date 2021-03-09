/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:42:12 by hroh              #+#    #+#             */
/*   Updated: 2021/03/09 21:44:22 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_action_ra(t_env *env, int mute)
{
	env->b_cnt = env->b_cnt;
	(void)mute;
	write(STDOUT_FILENO, "ra\n", 3);
}

void	ft_action_rb(t_env *env, int mute)
{
	env->b_cnt = env->b_cnt;
	(void)mute;
	write(STDOUT_FILENO, "rb\n", 3);
}

void	ft_action_rr(t_env *env)
{
	env->b_cnt = env->b_cnt;
	write(STDOUT_FILENO, "rr\n", 3);
}
