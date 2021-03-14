/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_s_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:38:26 by hroh              #+#    #+#             */
/*   Updated: 2021/03/14 14:37:41 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_action_sa(t_env *env, int mute)
{
	char *temp;

	temp = env->arr_a[1];
	env->arr_a[1] = env->arr_a[0];
	env->arr_a[0] = temp;
	if (mute != 1)
		write(STDOUT_FILENO, "sa\n", 3);
}

void	ft_action_sb(t_env *env, int mute)
{
	char *temp;

	temp = env->arr_b[1];
	env->arr_b[1] = env->arr_b[0];
	env->arr_b[0] = temp;
	if (mute != 1)
		write(STDOUT_FILENO, "sb\n", 3);
}

void	ft_action_ss(t_env *env, int mute)
{
	ft_action_sa(env, 1);
	ft_action_sb(env, 1);
	if (mute != 1)
		write(STDOUT_FILENO, "ss\n", 3);
}

void	ft_action_pa(t_env *env, int mute)
{
	char	*temp;

	if (env->b_cnt > 0)
	{
		ft_action_rra(env, 1, 1);
		temp = env->arr_a[0];
		env->arr_a[0] = env->arr_b[0];
		env->arr_b[0] = temp;
		ft_action_rb(env, 1);
		env->b_cnt--;
		env->a_cnt++;
	}
	if (mute != 1)
		write(STDOUT_FILENO, "pa\n", 3);
}

void	ft_action_pb(t_env *env, int mute)
{
	char	*temp;

	if (env->a_cnt > 0)
	{
		ft_action_rrb(env, 1, 1);
		temp = env->arr_b[0];
		env->arr_b[0] = env->arr_a[0];
		env->arr_a[0] = temp;
		ft_action_ra(env, 1);
		env->a_cnt--;
		env->b_cnt++;
	}
	if (mute != 1)
		write(STDOUT_FILENO, "pb\n", 3);
}
