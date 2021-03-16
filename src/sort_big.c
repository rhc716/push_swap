/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:24:10 by hroh              #+#    #+#             */
/*   Updated: 2021/03/16 22:05:59 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_save_low_cost(t_env *env, int l, int r)
{
	int l_cost;
	int r_cost;
	int l_rb_temp;

	l_cost = ft_get_rb_cnt(env, ft_atoi(env->arr_a[l])) + l;
	l_rb_temp = env->before_pb_rb;
	r_cost = ft_get_rb_cnt(env, ft_atoi(env->arr_a[r])) + env->a_cnt - r;
	if ((env->save_cost > l_cost || env->save_cost > r_cost) &&
		(l_cost <= r_cost))
	{
		env->save_cost = l_cost;
		env->save_rb = l_rb_temp;
		env->save_ra = l;
	}
	if ((env->save_cost > l_cost || env->save_cost > r_cost) &&
		(l_cost > r_cost))
	{
		env->save_cost = r_cost;
		env->save_rb = env->before_pb_rb;
		env->save_ra = r - env->a_cnt;
	}
}

void	ft_get_pb_target(t_env *env)
{
	int l;
	int r;

	l = 0;
	r = env->a_cnt - 1;
	env->save_cost = 2147483647;
	env->save_ra = 0;
	env->save_rb = 0;
	while (l <= r)
	{
		ft_save_low_cost(env, l, r);
		l++;
		r--;
	}
	if (l == 0)
		return ;
	env->before_pb_rb = env->save_rb;
	env->before_pb_ra = env->save_ra;
}

void	ft_sort_pb_loop(t_env *env)
{
	ft_get_pb_target(env);
	while (env->before_pb_ra > 0 && env->before_pb_rb > 0)
		ft_action_rr(env, 0, -1);
	while (env->before_pb_ra < 0 && env->before_pb_rb < 0)
		ft_action_rrr(env, 0, 1);
	while (env->before_pb_ra > 0)
		ft_action_ra(env, 0, -1);
	while (env->before_pb_ra < 0)
		ft_action_rra(env, 0, 0, 1);
	while (env->before_pb_rb > 0)
		ft_action_rb(env, 0, -1);
	while (env->before_pb_rb < 0)
		ft_action_rrb(env, 0, 0, 1);
	ft_action_pb(env, 0);
}

void	ft_sort_big(t_env *env)
{
	while (env->a_cnt > 0)
		ft_sort_pb_loop(env);
	if (ft_is_b_desc(env) != 1)
	{
		ft_get_rb_cnt(env, 0);
		if (env->before_pb_rb > 0)
			while (--env->before_pb_rb >= 0)
				ft_action_rb(env, 0, 0);
		else if (env->before_pb_rb < 0)
			while (++env->before_pb_rb <= 0)
				ft_action_rrb(env, 0, 0, 0);
	}
	while (env->b_cnt > 0)
		ft_action_pa(env, 0);
}
