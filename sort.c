/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 22:16:47 by hroh              #+#    #+#             */
/*   Updated: 2021/03/10 21:02:55 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_env *env)
{
	int gap;
	int cnt;

	while (env->a_cnt > 0)
	{
		ft_find_lowest(env);
		gap = env->a_cnt - env->lowest_pos;
		if (gap < env->lowest_pos)
		{
			gap++;
			while (--gap >= 0)
				ft_action_rra(env, 0, 0);
			ft_action_pb(env, 0);
		}
		else
		{
			while (--env->lowest_pos > 0)
				ft_action_ra(env, 0);
			ft_action_pb(env, 0);
		}
	}
	cnt = env->ori_cnt + 1;
	while (--cnt > 0)
		ft_action_pa(env, 0);
}
