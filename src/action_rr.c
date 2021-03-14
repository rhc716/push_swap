/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:41:22 by hroh              #+#    #+#             */
/*   Updated: 2021/03/14 14:37:38 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_action_rra(t_env *env, int mute, int push_call)
{
	int		i;
	char	*last;

	i = env->a_cnt - 1;
	if (env->a_cnt == 0)
		return ;
	if (i < 0)
		i = 0;
	if (push_call == 1)
		i = env->ori_cnt - 1;
	last = env->arr_a[i];
	while (i >= 0)
	{
		if (i == 0)
			env->arr_a[i] = last;
		else
			env->arr_a[i] = env->arr_a[i - 1];
		i--;
	}
	if (mute != 1)
		write(STDOUT_FILENO, "rra\n", 4);
}

void	ft_action_rrb(t_env *env, int mute, int push_call)
{
	int		i;
	char	*last;

	i = env->b_cnt - 1;
	if (env->b_cnt == 0)
		return ;
	if (i < 0)
		i = 0;
	if (push_call == 1)
		i = env->ori_cnt - 1;
	last = env->arr_b[i];
	while (i >= 0)
	{
		if (i == 0)
			env->arr_b[i] = last;
		else
			env->arr_b[i] = env->arr_b[i - 1];
		i--;
	}
	if (mute != 1)
		write(STDOUT_FILENO, "rrb\n", 4);
}

void	ft_action_rrr(t_env *env, int mute)
{
	ft_action_rra(env, 1, 0);
	ft_action_rrb(env, 1, 0);
	if (mute != 1)
		write(STDOUT_FILENO, "rrr\n", 4);
}
