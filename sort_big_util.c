/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:00:53 by hroh              #+#    #+#             */
/*   Updated: 2021/03/12 16:05:47 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_b_desc(t_env *env)
{
	int i;

	i = 0;
	while (i + 1 < env->b_cnt)
	{
		if (env->arr_b[i] < env->arr_b[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		ft_find_b_max(t_env *env)
{
	int max;
	int n;
	int i;

	max = ft_atoi(env->arr_b[0]);
	env->b_max_pos = 0;
	i = 0;
	while (env->arr_b[++i] && i < env->b_cnt)
	{
		if ((n = ft_atoi(env->arr_b[i])) > max)
		{
			max = n;
			env->b_max_pos = i;
		}
	}
	return (env->b_max_pos);
}

int		ft_find_pb_pos(t_env *env, int a)
{
	int i;
	int first_set;

	i = 0;
	env->pb_pos = 0;
	first_set = 0;
	if (env->b_cnt < 2)
		return (0);
	while (env->arr_b[i] && i < env->b_cnt)
	{
		if (first_set == 0 && a > ft_atoi(env->arr_b[i]))
		{
			first_set = 1;
			env->pb_pos = i;
		}
		else if (first_set == 1 && a > ft_atoi(env->arr_b[i]) &&
			ft_atoi(env->arr_b[env->pb_pos]) < ft_atoi(env->arr_b[i]))
			env->pb_pos = i;
		i++;
	}
	if (first_set == 0 && ft_find_b_max(env) != 0)
		return (env->pb_pos = env->b_max_pos);
	return (env->pb_pos);
}

int		ft_get_rb_cnt(t_env *env, int a)
{
	ft_find_pb_pos(env, a);
	if (env->pb_pos == 0)
		return (env->before_pb_rb = 0);
	if (env->pb_pos <= env->b_cnt / 2)
		return (env->before_pb_rb = env->pb_pos);
	if (env->pb_pos > env->b_cnt / 2)
		return (-1 * (env->before_pb_rb = env->pb_pos - env->b_cnt));
	return (0);
}
