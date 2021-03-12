/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 21:27:54 by hroh              #+#    #+#             */
/*   Updated: 2021/03/12 15:56:41 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3_num(t_env *env)
{
	ft_find_a_min(env, env->a_cnt);
	if (ft_is_ok(env, 3))
		return ;
	if (env->a_min_pos == 1)
	{
		ft_action_sa(env, 0);
		ft_action_ra(env, 0);
	}
	else if (env->a_min_pos == 2 &&
			ft_atoi(env->arr_a[0]) < ft_atoi(env->arr_a[2]))
		ft_action_sa(env, 0);
	else if (env->a_min_pos == 2 &&
			ft_atoi(env->arr_a[0]) > ft_atoi(env->arr_a[2]))
		ft_action_ra(env, 0);
	else if (env->a_min_pos == 3 &&
			ft_atoi(env->arr_a[0]) < ft_atoi(env->arr_a[1]))
		ft_action_rra(env, 0, 0);
	else
	{
		ft_action_sa(env, 0);
		ft_action_rra(env, 0, 0);
	}
}

void	ft_sort_5_num(t_env *env, int num)
{
	int rra_cnt;
	int i;

	i = num - 2;
	while (--i > 0)
	{
		ft_find_a_min(env, env->a_cnt);
		rra_cnt = env->a_cnt - env->a_min_pos + 1;
		if (rra_cnt < env->a_min_pos - 1)
			while (--rra_cnt >= 0)
				ft_action_rra(env, 0, 0);
		else
			while (--env->a_min_pos > 0)
				ft_action_ra(env, 0);
		if (ft_is_ok(env, num))
			return ;
		ft_action_pb(env, 0);
	}
	ft_sort_3_num(env);
	ft_action_pa(env, 0);
	if (num == 5)
		ft_action_pa(env, 0);
}
