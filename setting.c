/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:28:24 by hroh              #+#    #+#             */
/*   Updated: 2021/03/10 21:06:33 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_make_arr_b(int argc)
{
	int		i;
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * (argc));
	ret[argc - 1] = NULL;
	i = 0;
	while (i < argc - 1)
	{
		ret[i] = (char *)malloc(sizeof(char) * 2);
		ret[i][0] = 'B';
		ret[i][1] = '\0';
		i++;
	}
	return (ret);
}

char	**ft_make_arr_a(int argc, char **argv)
{
	int		i;
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * (argc));
	ret[argc - 1] = NULL;
	i = 0;
	while (i < argc - 1)
	{
		ret[i] = ft_strdup(argv[i + 1]);
		i++;
	}
	return (ret);
}

void	ft_find_lowest(t_env *env)
{
	int i;
	int n;

	env->lowest = ft_atoi(env->arr_a[0]);
	env->lowest_pos = 0;
	i = 0;
	while (env->arr_a[i] && env->arr_a[i + 1])
	{
		if (env->arr_a[i + 1][0] != 'B' &&
			((n = ft_atoi(env->arr_a[i + 1])) < env->lowest))
		{
			env->lowest = n;
			env->lowest_pos = i + 2;
		}
		i++;
	}
}

void	ft_set_env(t_env *env, int argc, char **argv)
{
	env->arr_a = ft_make_arr_a(argc, argv);
	env->arr_b = ft_make_arr_b(argc);
	env->a_cnt = argc - 1;
	env->ori_cnt = env->a_cnt;
	env->b_cnt = 0;
	ft_find_lowest(env);
}
