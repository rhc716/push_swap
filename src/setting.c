/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:28:24 by hroh              #+#    #+#             */
/*   Updated: 2021/03/14 14:38:08 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int		ft_find_a_min(t_env *env, int end)
{
	int		i;
	int		n;

	env->a_min = ft_atoi(env->arr_a[0]);
	env->a_min_pos = 1;
	i = 0;
	while (env->arr_a[++i] && i < end)
	{
		if (((n = ft_atoi(env->arr_a[i])) < env->a_min))
		{
			env->a_min = n;
			env->a_min_pos = i + 1;
		}
	}
	return (env->a_min_pos);
}

void	ft_set_env(t_env *env, int argc, char **argv)
{
	env->arr_a = ft_make_arr_a(argc, argv);
	env->arr_b = ft_make_arr_b(argc);
	env->a_cnt = argc - 1;
	env->ori_cnt = env->a_cnt;
	env->b_cnt = 0;
	env->before_pb_rb = 0;
	env->before_pb_ra = 0;
	env->pb_pos = 0;
	ft_find_a_min(env, env->a_cnt);
}
