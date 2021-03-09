/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_s_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:38:26 by hroh              #+#    #+#             */
/*   Updated: 2021/03/09 21:45:00 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_action_sa(t_env *env, int mute)
{
	int *temp;

	temp = env->arr_a[1];
	env->arr_a[1] = env->arr_a[0];
	env->arr_a[0] = temp;
	if (mute != 1)
		write(STDOUT_FILENO, "sa\n", 3);
}

void	ft_action_sb(t_env *env, int mute)
{
	int *temp;

	temp = env->arr_b[1];
	env->arr_b[1] = env->arr_b[0];
	env->arr_b[0] = temp;
	if (mute != 1)
		write(STDOUT_FILENO, "sb\n", 3);
}

void	ft_action_ss(t_env *env)
{
	ft_action_sa(env, 1);
	ft_action_sb(env, 1);
	write(STDOUT_FILENO, "ss\n", 3);
}

void	ft_action_pa(t_env *env)
{
	//int i;
	//int *temp;

	env->b_cnt = env->b_cnt;
	//i = 0;
	write(STDOUT_FILENO, "pa\n", 3);
}

void	ft_action_pb(t_env *env)
{
	env->b_cnt = env->b_cnt;
	write(STDOUT_FILENO, "pb\n", 3);
}
