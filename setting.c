/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:28:24 by hroh              #+#    #+#             */
/*   Updated: 2021/03/09 22:14:57 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 
int		**ft_make_arr_b(int argc)
{
	int i;
	int **ret;

	ret = (int **)malloc(sizeof(int *) * (argc - 1));
	i = -1;
	while (++i < argc - 1)
	{
		ret[i] = (int *)malloc(sizeof(int));
		*ret[i] = 0;
	}
	return (ret);
}

int		**ft_cast_int_argv(int argc, char **argv)
{
	int i;
	int **ret;

	ret = (int **)malloc(sizeof(int *) * (argc - 1));
	i = -1;
	while (++i < argc - 1)
	{
		ret[i] = (int *)malloc(sizeof(int));
		*ret[i] = ft_atoi(argv[i + 1]);
	}
	return (ret);
}

void	ft_set_peak_and_sorted_num(t_env *env, int end)
{
	int i;
	int peak;

	i = -1;
	peak = **(env->arr_a);
	while (++i < end)
	{
		if (*(env->arr_a[i]) > peak)
			peak = *(env->arr_a[i]);
	}
	if (*(env->arr_a[end - 1]) == peak && end - 1 > 0)
	{
		env->sorted_num = end - 1;
		ft_set_peak_and_sorted_num(env, end - 1);
	}
	else
		env->peak = peak;
}

void	ft_set_env(t_env *env, int argc, char **argv)
{
	env->arr_a = ft_cast_int_argv(argc, argv);
	env->arr_b = ft_make_arr_b(argc);
	env->a_cnt = argc - 1;
	env->b_cnt = 0;
	env->ok = 0;
	env->sorted_num = 0;
	ft_set_peak_and_sorted_num(env, env->a_cnt);
	if (env->sorted_num == 1)
		env->ok = 1;
}
