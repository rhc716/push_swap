/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 22:16:47 by hroh              #+#    #+#             */
/*   Updated: 2021/03/14 14:38:32 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort(t_env *env)
{
	if (env->ori_cnt == 2)
		ft_action_sa(env, 0);
	else if (env->ori_cnt == 3)
		ft_sort_3_num(env);
	else if (env->ori_cnt <= 5)
		ft_sort_5_num(env, env->ori_cnt);
	else
		ft_sort_big(env);
}
