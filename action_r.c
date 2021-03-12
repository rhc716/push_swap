/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:42:12 by hroh              #+#    #+#             */
/*   Updated: 2021/03/11 19:45:01 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_action_ra(t_env *env, int mute)
{
	int		i;
	char	*first;

	i = 0;
	first = env->arr_a[0];
	if (env->a_cnt == 0)
		return ;
	while (i < env->a_cnt)
	{
		if (i == env->a_cnt - 1)
			env->arr_a[i] = first;
		else
			env->arr_a[i] = env->arr_a[i + 1];
		i++;
	}
	if (mute != 1)
		write(STDOUT_FILENO, "ra\n", 3);
}

void	ft_action_rb(t_env *env, int mute)
{
	int		i;
	char	*first;

	i = 0;
	first = env->arr_b[0];
	if (env->b_cnt == 0)
		return ;
	while (i < env->b_cnt)
	{
		if (i == env->b_cnt - 1)
			env->arr_b[i] = first;
		else
			env->arr_b[i] = env->arr_b[i + 1];
		i++;
	}
	if (mute != 1)
		write(STDOUT_FILENO, "rb\n", 3);
}

void	ft_action_rr(t_env *env, int mute)
{
	ft_action_ra(env, 1);
	ft_action_rb(env, 1);
	if (mute != 1)
		write(STDOUT_FILENO, "rr\n", 3);
}
